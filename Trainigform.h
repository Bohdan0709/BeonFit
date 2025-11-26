#pragma once
#include "Services.h" 

namespace BeonFit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class Trainigform : public System::Windows::Forms::Form
	{
	private:
		String^ userLogin;
		String^ exerciseName;
		String^ historyText = "";
		int totalCalories = 0;

	public:
		Trainigform(String^ login)
		{
			InitializeComponent();
			userLogin = login;
		}

	protected:
		~Trainigform()
		{
			if (components) delete components;
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NotifyIcon^ notifyIcon1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // label1
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->label1->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label1->Location = System::Drawing::Point(272, 95);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(87, 22);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Exercies";
			   // textBox1
			   this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox1->Enabled = false;
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->textBox1->ForeColor = System::Drawing::Color::White;
			   this->textBox1->Location = System::Drawing::Point(93, 129);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(445, 59);
			   this->textBox1->TabIndex = 1;
			   this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   // button1
			   this->button1->BackColor = System::Drawing::Color::Orange;
			   this->button1->FlatAppearance->BorderSize = 0;
			   this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->button1->ForeColor = System::Drawing::Color::White;
			   this->button1->Location = System::Drawing::Point(93, 206);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(136, 45);
			   this->button1->TabIndex = 2;
			   this->button1->Text = L"Choose another exercise";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &Trainigform::button1_Click);
			   // button2
			   this->button2->BackColor = System::Drawing::Color::Orange;
			   this->button2->FlatAppearance->BorderSize = 0;
			   this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->button2->ForeColor = System::Drawing::Color::White;
			   this->button2->Location = System::Drawing::Point(249, 206);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(136, 45);
			   this->button2->TabIndex = 3;
			   this->button2->Text = L"Exercise done";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &Trainigform::button2_Click);
			   // label3
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->label3->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label3->Location = System::Drawing::Point(23, 379);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(132, 20);
			   this->label3->TabIndex = 5;
			   this->label3->Text = L"Burned calories:";
			   // label4
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->label4->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label4->Location = System::Drawing::Point(178, 379);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(59, 20);
			   this->label4->TabIndex = 6;
			   this->label4->Text = L"label4";
			   // label5
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->label5->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label5->Location = System::Drawing::Point(23, 342);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(53, 20);
			   this->label5->TabIndex = 7;
			   this->label5->Text = L"label5";
			   // button3
			   this->button3->BackColor = System::Drawing::Color::Orange;
			   this->button3->FlatAppearance->BorderSize = 0;
			   this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->button3->ForeColor = System::Drawing::Color::White;
			   this->button3->Location = System::Drawing::Point(402, 206);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(136, 45);
			   this->button3->TabIndex = 3;
			   this->button3->Text = L"Finish training";
			   this->button3->UseVisualStyleBackColor = false;
			   this->button3->Click += gcnew System::EventHandler(this, &Trainigform::button3_Click);
			   // panel1
			   this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->panel1->Controls->Add(this->button4);
			   this->panel1->Controls->Add(this->textBox6);
			   this->panel1->Controls->Add(this->textBox5);
			   this->panel1->Controls->Add(this->textBox4);
			   this->panel1->Controls->Add(this->textBox3);
			   this->panel1->Controls->Add(this->textBox2);
			   this->panel1->Controls->Add(this->label9);
			   this->panel1->Controls->Add(this->label8);
			   this->panel1->Controls->Add(this->label7);
			   this->panel1->Controls->Add(this->label6);
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Location = System::Drawing::Point(155, 12);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(334, 389);
			   this->panel1->TabIndex = 9;
			   // button4
			   this->button4->BackColor = System::Drawing::Color::Orange;
			   this->button4->FlatAppearance->BorderSize = 0;
			   this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->button4->ForeColor = System::Drawing::Color::White;
			   this->button4->Location = System::Drawing::Point(99, 336);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(119, 23);
			   this->button4->TabIndex = 10;
			   this->button4->Text = L"Sent";
			   this->button4->UseVisualStyleBackColor = false;
			   this->button4->Click += gcnew System::EventHandler(this, &Trainigform::button4_Click);
			   // textBoxes
			   this->textBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox6->ForeColor = System::Drawing::Color::White;
			   this->textBox6->Location = System::Drawing::Point(176, 283);
			   this->textBox6->Name = L"textBox6";
			   this->textBox6->Size = System::Drawing::Size(100, 22);
			   this->textBox6->TabIndex = 9;
			   this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox5->ForeColor = System::Drawing::Color::White;
			   this->textBox5->Location = System::Drawing::Point(176, 226);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->Size = System::Drawing::Size(100, 22);
			   this->textBox5->TabIndex = 8;
			   this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox4->ForeColor = System::Drawing::Color::White;
			   this->textBox4->Location = System::Drawing::Point(176, 169);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(100, 22);
			   this->textBox4->TabIndex = 7;
			   this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox3->ForeColor = System::Drawing::Color::White;
			   this->textBox3->Location = System::Drawing::Point(176, 104);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(100, 22);
			   this->textBox3->TabIndex = 6;
			   this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox2->ForeColor = System::Drawing::Color::White;
			   this->textBox2->Location = System::Drawing::Point(176, 46);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(100, 22);
			   this->textBox2->TabIndex = 5;
			   // labels
			   this->label9->AutoSize = true;
			   this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->label9->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label9->Location = System::Drawing::Point(76, 283);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(66, 18);
			   this->label9->TabIndex = 4;
			   this->label9->Text = L"Arm size";
			   this->label8->AutoSize = true;
			   this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->label8->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label8->Location = System::Drawing::Point(76, 229);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(63, 18);
			   this->label8->TabIndex = 3;
			   this->label8->Text = L"Leg size";
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->label7->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label7->Location = System::Drawing::Point(76, 172);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(73, 18);
			   this->label7->TabIndex = 2;
			   this->label7->Text = L"Back size";
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->label6->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label6->Location = System::Drawing::Point(76, 104);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(78, 18);
			   this->label6->TabIndex = 1;
			   this->label6->Text = L"Chest size";
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->label2->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label2->Location = System::Drawing::Point(76, 46);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(54, 18);
			   this->label2->TabIndex = 0;
			   this->label2->Text = L"Weight";
			   // notifyIcon
			   this->notifyIcon1->Text = L"notifyIcon1";
			   this->notifyIcon1->Visible = true;
			   // Trainigform
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->ClientSize = System::Drawing::Size(617, 413);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->button2);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Name = L"Trainigform";
			   this->Text = L"Trainigform";
			   this->Load += gcnew System::EventHandler(this, &Trainigform::Trainigform_Load);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void Trainigform_Load(System::Object^ sender, System::EventArgs^ e) {
		panel1->Visible = false;
		label5->Text = DateTime::Now.ToString("dd.MM.yyyy");
		totalCalories = 0;
		label4->Text = totalCalories.ToString();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(userLogin)) return;

		int timeDummy = 0;
		// Виклик сервісу
		String^ result = TrainingService::GetRandomExercise(userLogin, timeDummy);

		textBox1->Text = result;

		if (result != "Exercise not found") {
			int spaceIndex = result->IndexOf(" ");
			if (spaceIndex > 0)
				exerciseName = result->Substring(0, spaceIndex);
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(userLogin) || String::IsNullOrEmpty(textBox1->Text)) return;

		try {
			int recCalories = 0;
			bool goalReached = false;

			// Виклик сервісу
			totalCalories = TrainingService::CalculateCalories(userLogin, exerciseName, totalCalories, recCalories, goalReached);

			label4->Text = totalCalories.ToString() + "/" + recCalories;

			if (!String::IsNullOrEmpty(historyText)) historyText += "\n";
			historyText += textBox1->Text;

			if (goalReached) {
				notifyIcon1->BalloonTipTitle = "BeonFit";
				notifyIcon1->BalloonTipText = "You have reached the recommended calorie burn!";
				notifyIcon1->Icon = SystemIcons::Information;
				notifyIcon1->Visible = true;
				notifyIcon1->ShowBalloonTip(3000);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(userLogin)) return;
		if (String::IsNullOrEmpty(historyText)) {
			MessageBox::Show("You didn't do any exercises");
			return;
		}
		panel1->Visible = true;
		button1->Visible = false;
		button2->Visible = false;
		label1->Visible = false;
		label3->Visible = false;
		label4->Visible = false;
		label5->Visible = false;
		textBox1->Visible = false;
		button3->Visible = false;
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ weight = textBox2->Text->Trim();
		String^ chest = textBox3->Text->Trim();
		String^ back = textBox4->Text->Trim();
		String^ leg = textBox5->Text->Trim();
		String^ arm = textBox6->Text->Trim();

		array<String^>^ inputs = { weight, chest, back, leg, arm };
		for each (String ^ s in inputs) {
			if (String::IsNullOrEmpty(s)) {
				MessageBox::Show("Please enter valid numeric values for all fields.");
				return;
			}
			for each (wchar_t c in s) {
				if (!Char::IsDigit(c)) {
					MessageBox::Show("Enter only digits!");
					return;
				}
			}
		}

		try {
			// Збереження в БД через сервіс
			TrainingService::SaveWorkout(userLogin, Convert::ToInt32(weight), Convert::ToInt32(chest),
				Convert::ToInt32(back), Convert::ToInt32(leg), Convert::ToInt32(arm), historyText, totalCalories);

			MessageBox::Show("Training data saved!");

			// Збереження у файл через сервіс
			FileService::SaveLogFile(userLogin, historyText, totalCalories);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}

		historyText = String::Empty;
		totalCalories = 0;

		panel1->Visible = false;
		button1->Visible = true;
		button2->Visible = true;
		label1->Visible = true;
		label3->Visible = true;
		label4->Visible = true;
		label5->Visible = true;
		textBox1->Visible = true;
		button3->Visible = true;
		textBox1->Clear();
		label4->Text = totalCalories.ToString();
		textBox2->Clear(); textBox3->Clear(); textBox4->Clear(); textBox5->Clear(); textBox6->Clear();
	}
	};
}