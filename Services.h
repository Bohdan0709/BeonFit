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
}