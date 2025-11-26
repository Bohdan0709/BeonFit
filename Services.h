#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::Odbc;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace BeonFit {

    // 1. Клас для роботи з підключенням до БД
    public ref class DbHelper {
    private:
        static String^ connectionString = "Driver={PostgreSQL Unicode};Server=localhost;Port=5432;Database=BeonFitDB;Uid=postgres;Pwd=;";
    public:
        static OdbcConnection^ GetConnection() {
            return gcnew OdbcConnection(connectionString);
        }
    };

    // 2. Сервіс авторизації 
    public ref class AuthService {
    public:
        static bool Login(String^ login, String^ password) {
            OdbcConnection^ conn = DbHelper::GetConnection();
            try {
                conn->Open();
                String^ query = "SELECT COUNT(*) FROM \"People\" WHERE \"Login\"=? AND \"Password\"=?";
                OdbcCommand^ cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@Login", login);
                cmd->Parameters->AddWithValue("@Password", password);
                int count = Convert::ToInt32(cmd->ExecuteScalar());
                return count > 0;
            }
            catch (Exception^ ex) {
                MessageBox::Show("DB Error: " + ex->Message);
                return false;
            }
            finally {
                conn->Close();
            }
        }

        static bool SignUp(String^ login, String^ password) {
            OdbcConnection^ conn = DbHelper::GetConnection();
            try {
                conn->Open();
                String^ query = "INSERT INTO \"People\" (\"Login\", \"Password\") VALUES (?, ?)";
                OdbcCommand^ cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@Login", login);
                cmd->Parameters->AddWithValue("@Password", password);
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^) {
                return false; // Швидше за все, такий логін вже існує
            }
            finally {
                conn->Close();
            }
        }
    };

    // 3. Сервіс профілю
    public ref class ProfileService {
    public:
        static void UpdateField(String^ login, String^ fieldName, Object^ value) {
            OdbcConnection^ conn = DbHelper::GetConnection();
            try {
                conn->Open();
                // Оновлення конкретного поля в таблиці People
                String^ query = "UPDATE \"People\" SET \"" + fieldName + "\" = ? WHERE \"Login\" = ?";
                OdbcCommand^ cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@Value", value);
                cmd->Parameters->AddWithValue("@Login", login);
                cmd->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error updating profile: " + ex->Message);
            }
            finally {
                conn->Close();
            }
        }

        static String^ GetField(String^ login, String^ fieldName) {
            OdbcConnection^ conn = DbHelper::GetConnection();
            try {
                conn->Open();
                String^ query = "SELECT \"" + fieldName + "\" FROM \"People\" WHERE \"Login\" = ?";
                OdbcCommand^ cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@Login", login);
                Object^ result = cmd->ExecuteScalar();

                if (result != nullptr && result != DBNull::Value) {
                    return result->ToString();
                }
                return "";
            }
            catch (Exception^ ex) {
                return "";
            }
            finally {
                conn->Close();
            }
        }
    };


    // 4. Сервіс тренувань
    public ref class TrainingService {
    public:
        static String^ GetRandomExercise(String^ login, int% outTime) {
            OdbcConnection^ conn = DbHelper::GetConnection();
            String^ resultText = "Exercise not found";
            outTime = 0;

            try {
                conn->Open();
                Random^ rnd = gcnew Random();
                int exerciseID = rnd->Next(1, 10); // ID від 1 до 9

                // Отримання назви
                String^ query = "SELECT \"Name_of_exercise\" FROM \"Exercise\" WHERE \"Exercise_ID\" = ?";
                OdbcCommand^ cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@Exercise_ID", exerciseID);
                Object^ objName = cmd->ExecuteScalar();

                if (objName == nullptr) return resultText;
                String^ exName = objName->ToString();

                // Отримання інтенсивності користувача
                query = "SELECT \"Intensity\" FROM \"People\" WHERE \"Login\" = ?";
                cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@Login", login);
                Object^ objIntensity = cmd->ExecuteScalar();

                int sets = 3;
                if (objIntensity != nullptr) {
                    String^ i = objIntensity->ToString();
                    if (i == "Medium") sets = 4;
                    else if (i == "High") sets = 5;
                }

                // Отримання повторів та часу
                query = "SELECT \"Reps\", \"Time_minutes\" FROM \"Exercise\" WHERE \"Name_of_exercise\" = ?";
                cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@Name", exName);
                OdbcDataReader^ reader = cmd->ExecuteReader();

                if (reader->Read()) {
                    String^ reps = reader["Reps"]->ToString();
                    int time = Convert::ToInt32(reader["Time_minutes"]);
                    outTime = time * sets;
                    resultText = String::Format("{0} {1}x{2} ({3} min)", exName, sets, reps, outTime);
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                return "Error: " + ex->Message;
            }
            finally {
                conn->Close();
            }
            return resultText;
        }

        static int CalculateCalories(String^ login, String^ exerciseName, int currentTotal, int% outRecCalories, bool% outGoalReached) {
            OdbcConnection^ conn = DbHelper::GetConnection();
            int newTotal = currentTotal;
            outRecCalories = 0;
            outGoalReached = false;

            try {
                conn->Open();

                // Базові калорії вправи
                String^ query = "SELECT \"Kalories\" FROM \"Exercise\" WHERE \"Name_of_exercise\" = ?";
                OdbcCommand^ cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@Name", exerciseName);
                Object^ calObj = cmd->ExecuteScalar();
                int baseCal = (calObj != nullptr) ? Convert::ToInt32(calObj) : 0;

                // Дані користувача
                query = "SELECT \"Intensity\", \"Target_waight\" FROM \"People\" WHERE \"Login\" = ?";
                cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@Login", login);
                OdbcDataReader^ reader = cmd->ExecuteReader();

                String^ intensity = "Easy";
                int targetWeight = 0;

                if (reader->Read()) {
                    if (reader["Intensity"] != DBNull::Value) intensity = reader["Intensity"]->ToString();
                    if (reader["Target_waight"] != DBNull::Value) targetWeight = Convert::ToInt32(reader["Target_waight"]);
                }
                reader->Close();

                // Поточна вага (остання записана)
                query = "SELECT \"Weight\" FROM \"Body\" WHERE \"Login\" = ? ORDER BY \"ID_process\" DESC LIMIT 1;";
                cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@Login", login);
                Object^ wObj = cmd->ExecuteScalar();
                int currentWeight = (wObj != nullptr) ? Convert::ToInt32(wObj) : 0;

                // Розрахунок коефіцієнта
                double k = 1.0;
                if (targetWeight != 0 && currentWeight != 0) {
                    double diff = currentWeight - targetWeight;
                    k = 1.0 + (diff * 0.02);
                    if (k < 0.5) k = 0.5;
                    if (k > 1.5) k = 1.5;
                }

                int sets = 3;
                double rec = 750 * k;

                if (intensity == "Medium") { sets = 4; rec = 900 * k; }
                else if (intensity == "High") { sets = 5; rec = 1100 * k; }

                newTotal += (baseCal * sets);
                outRecCalories = (int)rec;

                if (outRecCalories <= newTotal) outGoalReached = true;
            }
            catch (Exception^) {}
            finally {
                conn->Close();
            }
            return newTotal;
        }

        static void SaveWorkout(String^ login, int weight, int chest, int back, int leg, int arm, String^ history, int cals) {
            OdbcConnection^ conn = DbHelper::GetConnection();
            try {
                conn->Open();
                String^ query = "INSERT INTO \"Body\" (\"Login\",\"Weight\",\"Chest_size\",\"Back_size\",\"Leg_size\",\"Arm_size\",\"Workout\",\"Calories_burned\",\"Data\") VALUES (?,?,?,?,?,?,?,?,?)";
                OdbcCommand^ cmd = gcnew OdbcCommand(query, conn);
                cmd->Parameters->AddWithValue("@p1", login);
                cmd->Parameters->AddWithValue("@p2", weight);
                cmd->Parameters->AddWithValue("@p3", chest);
                cmd->Parameters->AddWithValue("@p4", back);
                cmd->Parameters->AddWithValue("@p5", leg);
                cmd->Parameters->AddWithValue("@p6", arm);
                cmd->Parameters->AddWithValue("@p7", history);
                cmd->Parameters->AddWithValue("@p8", cals);
                cmd->Parameters->AddWithValue("@p9", DateTime::Now);
                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }
    };

    // 5. Сервіс файлів (Збереження на робочий стіл)
    public ref class FileService {
    public:
        static void SaveLogFile(String^ login, String^ history, int calories) {
            try {
                DateTime now = DateTime::Now;
                String^ fileNameOnly = "Workout_" + now.ToString("yyyy-MM-dd_HH-mm") + ".txt";
                String^ desktopPath = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
                String^ fullPath = Path::Combine(desktopPath, fileNameOnly);

                StreamWriter^ sw = gcnew StreamWriter(fullPath);
                sw->WriteLine("DATE: " + now.ToString());
                sw->WriteLine("USER: " + login);
                sw->WriteLine("====================================");
                sw->WriteLine("WORKOUT LOG:");
                sw->WriteLine("====================================");
                sw->WriteLine(history);
                sw->WriteLine("====================================");
                sw->WriteLine("TOTAL CALORIES: " + calories);
                sw->Close();

                MessageBox::Show("File saved to Desktop:\n" + fileNameOnly, "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (Exception^ ex) {
                MessageBox::Show("File save error: " + ex->Message);
            }
        }
    };

    // 6. Сервіс статистики (Для графіків)
    public ref class StatsService {
    public:
        static OdbcDataReader^ GetChartData(OdbcConnection^ conn, String^ columns) {
            // Передаємо відкрите з'єднання, бо DataReader потребує його активним
            String^ query = "SELECT \"Data\", " + columns + " FROM public.\"Body\" ORDER BY \"Data\" ASC;";
            OdbcCommand^ cmd = gcnew OdbcCommand(query, conn);
            return cmd->ExecuteReader();
        }
    };
}