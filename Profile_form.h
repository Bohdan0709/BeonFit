#pragma once
#include "Services.h"

namespace BeonFit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Profile_form : public System::Windows::Forms::Form
	{
	private:
		String^ userLogin;
	public:
		Profile_form(String^ login)
		{
			InitializeComponent();
			userLogin = login;
		}

	protected:
		~Profile_form()
		{
			if (components) delete components;
		}

	private: FontAwesome::Sharp::IconButton^ iconButton1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->iconButton1 = (gcnew FontAwesome::Sharp::IconButton());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->SuspendLayout();
			   // 
			   // iconButton1
			   // 
			   this->iconButton1->BackColor = System::Drawing::Color::Orange;
			   this->iconButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->iconButton1->Flip = FontAwesome::Sharp::FlipOrientation::Normal;
			   this->iconButton1->IconChar = FontAwesome::Sharp::IconChar::User;
			   this->iconButton1->IconColor = System::Drawing::Color::Black;
			   this->iconButton1->IconSize = 50;
			   this->iconButton1->Location = System::Drawing::Point(241, 12);
			   this->iconButton1->Name = L"iconButton1";
			   this->iconButton1->Rotation = 0;
			   this->iconButton1->Size = System::Drawing::Size(122, 106);
			   this->iconButton1->TabIndex = 0;
			   this->iconButton1->UseVisualStyleBackColor = false;
			   this->iconButton1->Click += gcnew System::EventHandler(this, &Profile_form::iconButton1_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label1->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label1->Location = System::Drawing::Point(265, 121);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(68, 25);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"Name";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label2->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label2->Location = System::Drawing::Point(109, 373);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(65, 18);
			   this->label2->TabIndex = 2;
			   this->label2->Text = L"Number:";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label3->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label3->Location = System::Drawing::Point(109, 166);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(61, 18);
			   this->label3->TabIndex = 3;
			   this->label3->Text = L"Gender:";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label4->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label4->Location = System::Drawing::Point(109, 209);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(61, 18);
			   this->label4->TabIndex = 4;
			   this->label4->Text = L"Growth:";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label5->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label5->Location = System::Drawing::Point(109, 291);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(100, 18);
			   this->label5->TabIndex = 5;
			   this->label5->Text = L"Target weight:";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label6->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label6->Location = System::Drawing::Point(109, 333);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(133, 18);
			   this->label6->TabIndex = 6;
			   this->label6->Text = L"Intensity of training:";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label7->ForeColor = System::Drawing::Color::Gainsboro;
			   this->label7->Location = System::Drawing::Point(109, 251);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(37, 18);
			   this->label7->TabIndex = 7;
			   this->label7->Text = L"Age:";
			   // 
			   // textBox2
			   // 
			   this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				   static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox2->ForeColor = System::Drawing::Color::White;
			   this->textBox2->Location = System::Drawing::Point(260, 204);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(132, 22);
			   this->textBox2->TabIndex = 9;
			   // 
			   // textBox3
			   // 
			   this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				   static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox3->ForeColor = System::Drawing::Color::White;
			   this->textBox3->Location = System::Drawing::Point(260, 247);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(132, 22);
			   this->textBox3->TabIndex = 10;
			   // 
			   // textBox4
			   // 
			   this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				   static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox4->ForeColor = System::Drawing::Color::White;
			   this->textBox4->Location = System::Drawing::Point(260, 288);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(132, 22);
			   this->textBox4->TabIndex = 11;
			   // 
			   // radioButton1
			   // 
			   this->radioButton1->AutoSize = true;
			   this->radioButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->radioButton1->ForeColor = System::Drawing::Color::Gainsboro;
			   this->radioButton1->Location = System::Drawing::Point(256, 162);
			   this->radioButton1->Name = L"radioButton1";
			   this->radioButton1->Size = System::Drawing::Size(77, 22);
			   this->radioButton1->TabIndex = 13;
			   this->radioButton1->TabStop = true;
			   this->radioButton1->Text = L"Female";
			   this->radioButton1->UseVisualStyleBackColor = true;
			   // 
			   // radioButton2
			   // 
			   this->radioButton2->AutoSize = true;
			   this->radioButton2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->radioButton2->ForeColor = System::Drawing::Color::Gainsboro;
			   this->radioButton2->Location = System::Drawing::Point(332, 162);
			   this->radioButton2->Name = L"radioButton2";
			   this->radioButton2->Size = System::Drawing::Size(60, 22);
			   this->radioButton2->TabIndex = 14;
			   this->radioButton2->TabStop = true;
			   this->radioButton2->Text = L"Male";
			   this->radioButton2->UseVisualStyleBackColor = true;
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::Color::Orange;
			   this->button1->FlatAppearance->BorderSize = 0;
			   this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button1->ForeColor = System::Drawing::Color::White;
			   this->button1->Location = System::Drawing::Point(417, 204);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(75, 23);
			   this->button1->TabIndex = 15;
			   this->button1->Text = L"Save";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &Profile_form::button1_Click);
			   // 
			   // button5
			   // 
			   this->button5->BackColor = System::Drawing::Color::Orange;
			   this->button5->FlatAppearance->BorderSize = 0;
			   this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button5->ForeColor = System::Drawing::Color::White;
			   this->button5->Location = System::Drawing::Point(417, 164);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(75, 23);
			   this->button5->TabIndex = 19;
			   this->button5->Text = L"Save";
			   this->button5->UseVisualStyleBackColor = false;
			   this->button5->Click += gcnew System::EventHandler(this, &Profile_form::button5_Click);
			   // 
			   // textBox1
			   // 
			   this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				   static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox1->ForeColor = System::Drawing::Color::White;
			   this->textBox1->Location = System::Drawing::Point(260, 370);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(132, 22);
			   this->textBox1->TabIndex = 20;
			   // 
			   // button6
			   // 
			   this->button6->BackColor = System::Drawing::Color::Orange;
			   this->button6->FlatAppearance->BorderSize = 0;
			   this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button6->ForeColor = System::Drawing::Color::White;
			   this->button6->Location = System::Drawing::Point(417, 371);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(75, 23);
			   this->button6->TabIndex = 21;
			   this->button6->Text = L"Save";
			   this->button6->UseVisualStyleBackColor = false;
			   this->button6->Click += gcnew System::EventHandler(this, &Profile_form::button6_Click);
			   // 
			   // button4
			   // 
			   this->button4->BackColor = System::Drawing::Color::Orange;
			   this->button4->FlatAppearance->BorderSize = 0;
			   this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button4->ForeColor = System::Drawing::Color::White;
			   this->button4->Location = System::Drawing::Point(417, 331);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(75, 23);
			   this->button4->TabIndex = 18;
			   this->button4->Text = L"Save";
			   this->button4->UseVisualStyleBackColor = false;
			   this->button4->Click += gcnew System::EventHandler(this, &Profile_form::button4_Click);
			   // 
			   // button3
			   // 
			   this->button3->BackColor = System::Drawing::Color::Orange;
			   this->button3->FlatAppearance->BorderSize = 0;
			   this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button3->ForeColor = System::Drawing::Color::White;
			   this->button3->Location = System::Drawing::Point(417, 289);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(75, 23);
			   this->button3->TabIndex = 17;
			   this->button3->Text = L"Save";
			   this->button3->UseVisualStyleBackColor = false;
			   this->button3->Click += gcnew System::EventHandler(this, &Profile_form::button3_Click);
			   // 
			   // button2
			   // 
			   this->button2->BackColor = System::Drawing::Color::Orange;
			   this->button2->FlatAppearance->BorderSize = 0;
			   this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button2->ForeColor = System::Drawing::Color::White;
			   this->button2->Location = System::Drawing::Point(417, 248);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(75, 23);
			   this->button2->TabIndex = 16;
			   this->button2->Text = L"Save";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &Profile_form::button2_Click);
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				   static_cast<System::Int32>(static_cast<System::Byte>(40)));
			   this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->comboBox1->ForeColor = System::Drawing::Color::White;
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Easy", L"Medium", L"High" });
			   this->comboBox1->Location = System::Drawing::Point(260, 330);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(132, 24);
			   this->comboBox1->TabIndex = 12;
			   // 
			   // Profile_form
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->ClientSize = System::Drawing::Size(617, 413);
			   this->Controls->Add(this->comboBox1);
			   this->Controls->Add(this->button6);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->button5);
			   this->Controls->Add(this->button4);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->radioButton2);
			   this->Controls->Add(this->radioButton1);
			   this->Controls->Add(this->textBox4);
			   this->Controls->Add(this->textBox3);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->label7);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->iconButton1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Name = L"Profile_form";
			   this->Text = L"Profile_form";
			   this->Load += gcnew System::EventHandler(this, &Profile_form::Profile_form_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

			   // --- ЗАВАНТАЖЕННЯ ДАНИХ ПРИ СТАРТІ ---
	private: System::Void Profile_form_Load(System::Object^ sender, System::EventArgs^ e) {
		if (!String::IsNullOrEmpty(userLogin)) {
			label1->Text = userLogin; // Показуємо логін юзера зверху

			// Викликаємо сервіс, щоб заповнити поля з БД
			textBox3->Text = ProfileService::GetField(userLogin, "Age");
			textBox2->Text = ProfileService::GetField(userLogin, "Growth");
			textBox4->Text = ProfileService::GetField(userLogin, "Target_waight");
			textBox1->Text = ProfileService::GetField(userLogin, "Number_phone");
			String^ currentIntensity = ProfileService::GetField(userLogin, "Intensity");
			if (!String::IsNullOrEmpty(currentIntensity)) {
				comboBox1->SelectedItem = currentIntensity; // Автоматично вибере потрібний пункт
			}

			String^ sex = ProfileService::GetField(userLogin, "Sex");
			if (sex == "Male") radioButton2->Checked = true;
			else if (sex == "Female") radioButton1->Checked = true;
		}
	}

		   // --- ОБРОБКА КНОПОК SAVE ---

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // GROWTH
		if (!String::IsNullOrEmpty(userLogin)) {
			try {
				int val = Convert::ToInt32(textBox2->Text);
				ProfileService::UpdateField(userLogin, "Growth", val);
				MessageBox::Show("Growth saved");
			}
			catch (Exception^ ex) { MessageBox::Show("Error: Input numbers only"); }
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // AGE
		if (!String::IsNullOrEmpty(userLogin)) {
			try {
				int val = Convert::ToInt32(textBox3->Text);
				ProfileService::UpdateField(userLogin, "Age", val);
				MessageBox::Show("Age saved");
			}
			catch (Exception^ ex) { MessageBox::Show("Error: Input numbers only"); }
		}
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // WEIGHT
		if (!String::IsNullOrEmpty(userLogin)) {
			try {
				int val = Convert::ToInt32(textBox4->Text);
				ProfileService::UpdateField(userLogin, "Target_waight", val);
				MessageBox::Show("Target waight saved");
			}
			catch (Exception^ ex) { MessageBox::Show("Error: Input numbers only"); }
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { // INTENSITY
		if (!String::IsNullOrEmpty(userLogin)) {
			if (comboBox1->SelectedItem == nullptr) {
				MessageBox::Show("Please select intensity level!");
				return;
			}

			String^ val = comboBox1->SelectedItem->ToString();

			// Тепер перевірка if/else не потрібна, бо користувач вибирає зі списку
			ProfileService::UpdateField(userLogin, "Intensity", val);
			MessageBox::Show("Intensity saved: " + val);
		}
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { // SEX
		if (!String::IsNullOrEmpty(userLogin)) {
			String^ sex = radioButton1->Checked ? "Female" : (radioButton2->Checked ? "Male" : "");
			if (sex != "") {
				ProfileService::UpdateField(userLogin, "Sex", sex);
				MessageBox::Show("Gender saved");
			}
		}
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { // PHONE
		if (!String::IsNullOrEmpty(userLogin)) {
			String^ val = textBox1->Text->Trim();
			if (val->Length != 10) {
				MessageBox::Show("The phone number must contain 10 digits!");
				return;
			}
			long long result;
			if (Int64::TryParse(val, result)) {
				ProfileService::UpdateField(userLogin, "Number_phone", val);
				MessageBox::Show("Number saved");
			}
			else {
				MessageBox::Show("Only digits!");
			}
		}
	}
	private: System::Void iconButton1_Click(System::Object^ sender, System::EventArgs^ e) {}
	};
}