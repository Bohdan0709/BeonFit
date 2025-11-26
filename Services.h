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
        // Рядок підключення (Змініть параметри, якщо у вас інший пароль або порт)
        static String^ connectionString = "Driver={PostgreSQL Unicode};Server=localhost;Port=5432;Database=BeonFitDB;Uid=postgres;Pwd=;";
    public:
        static OdbcConnection^ GetConnection() {
            return gcnew OdbcConnection(connectionString);
        }
    };
}