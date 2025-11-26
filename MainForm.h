#pragma once
#include "Services.h"

namespace BeonFit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace FontAwesome::Sharp;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		bool dragging = false;
		Point dragCursorPoint;
		Point dragFormPoint;

	public:
		static String^ LoggedInUser; // Статична змінна для сесії

		MainForm(void)
		{
			this->StartPosition = FormStartPosition::CenterScreen;
			InitializeComponent();
			LockMenu();

			leftBorderBtn = gcnew System::Windows::Forms::Panel();
			leftBorderBtn->Size = System::Drawing::Size(7, 82);
			panelmenu->Controls->Add(leftBorderBtn);

			label4->Font = gcnew System::Drawing::Font("Segoe UI", 14, System::Drawing::FontStyle::Bold);
			label4->ForeColor = System::Drawing::Color::Orange;
			label4->AutoSize = true;
			label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		}

	protected:
		~MainForm()
		{
			if (components) delete components;
		}

	private: System::Windows::Forms::Timer^ timerClock;
	private: FontAwesome::Sharp::IconButton^ iconButton6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panelmenu;
	private: System::Windows::Forms::PictureBox^ iconic;
	private: System::Windows::Forms::Panel^ panelheader;
	private: System::Windows::Forms::Panel^ panelmain;
	private: FontAwesome::Sharp::IconButton^ iconButton2;
	private: FontAwesome::Sharp::IconButton^ iconButton4;
	private: FontAwesome::Sharp::IconButton^ iconButton3;
	private: FontAwesome::Sharp::IconButton^ iconButton1;
	private: FontAwesome::Sharp::IconButton^ currentBtn;
	private: System::Windows::Forms::Panel^ leftBorderBtn;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: FontAwesome::Sharp::IconButton^ iconButton5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: FontAwesome::Sharp::IconButton^ iconButton7;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;

	private:
		void LockMenu() {
			iconButton1->Enabled = false;
			iconButton2->Enabled = false;
			iconButton3->Enabled = false;
			iconButton1->IconColor = System::Drawing::Color::DimGray;
			iconButton1->ForeColor = System::Drawing::Color::DimGray;
			iconButton2->IconColor = System::Drawing::Color::DimGray;
			iconButton2->ForeColor = System::Drawing::Color::DimGray;
			iconButton3->IconColor = System::Drawing::Color::DimGray;
			iconButton3->ForeColor = System::Drawing::Color::DimGray;
		}

		void UnlockMenu() {
			iconButton1->Enabled = true;
			iconButton2->Enabled = true;
			iconButton3->Enabled = true;
			DisableButton();
		}

		void ActivateButton(System::Object^ senderBtn) {
			if (senderBtn != nullptr) {
				DisableButton();
				currentBtn = (IconButton^)senderBtn;
				currentBtn->ForeColor = System::Drawing::Color::Orange;
				currentBtn->IconColor = System::Drawing::Color::Orange;
				currentBtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				currentBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleCenter;

				leftBorderBtn->BackColor = System::Drawing::Color::Orange;
				leftBorderBtn->Location = System::Drawing::Point(0, currentBtn->Location.Y);
				leftBorderBtn->Visible = true;
				leftBorderBtn->BringToFront();
			}
		}

		void DisableButton() {
			if (currentBtn != nullptr) {
				currentBtn->BackColor = System::Drawing::Color::Transparent;
				currentBtn->ForeColor = System::Drawing::Color::Gainsboro;
				currentBtn->IconColor = System::Drawing::Color::Gainsboro;
				currentBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
				currentBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				currentBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
				leftBorderBtn->Visible = false;
			}
			if (iconButton1->Enabled) {
				iconButton1->ForeColor = System::Drawing::Color::Gainsboro; iconButton1->IconColor = System::Drawing::Color::Gainsboro;
				iconButton2->ForeColor = System::Drawing::Color::Gainsboro; iconButton2->IconColor = System::Drawing::Color::Gainsboro;
				iconButton3->ForeColor = System::Drawing::Color::Gainsboro; iconButton3->IconColor = System::Drawing::Color::Gainsboro;
			}
		}

		void CenterClock() {
			if (panelheader != nullptr && label4 != nullptr) {
				label4->Location = System::Drawing::Point(
					(panelheader->Width - label4->Width) / 2,
					(panelheader->Height - label4->Height) / 2
				);
			}
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->panelmenu = (gcnew System::Windows::Forms::Panel());
			this->iconButton4 = (gcnew FontAwesome::Sharp::IconButton());
			this->iconButton3 = (gcnew FontAwesome::Sharp::IconButton());
			this->iconButton1 = (gcnew FontAwesome::Sharp::IconButton());
			this->iconButton2 = (gcnew FontAwesome::Sharp::IconButton());
			this->iconic = (gcnew System::Windows::Forms::PictureBox());
			this->panelheader = (gcnew System::Windows::Forms::Panel());
			this->iconButton7 = (gcnew FontAwesome::Sharp::IconButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panelmain = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->iconButton6 = (gcnew FontAwesome::Sharp::IconButton());
			this->iconButton5 = (gcnew FontAwesome::Sharp::IconButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timerClock = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelmenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->iconic))->BeginInit();
			this->panelheader->SuspendLayout();
			this->panelmain->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelmenu
			// 
			this->panelmenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->panelmenu->Controls->Add(this->iconButton4);
			this->panelmenu->Controls->Add(this->iconButton3);
			this->panelmenu->Controls->Add(this->iconButton1);
			this->panelmenu->Controls->Add(this->iconButton2);
			this->panelmenu->Controls->Add(this->iconic);
			this->panelmenu->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelmenu->Location = System::Drawing::Point(0, 0);
			this->panelmenu->Name = L"panelmenu";
			this->panelmenu->Size = System::Drawing::Size(242, 487);
			this->panelmenu->TabIndex = 0;
			// 
			// iconButton4
			// 
			this->iconButton4->BackColor = System::Drawing::Color::Transparent;
			this->iconButton4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->iconButton4->FlatAppearance->BorderSize = 0;
			this->iconButton4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->iconButton4->Flip = FontAwesome::Sharp::FlipOrientation::Normal;
			this->iconButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->iconButton4->ForeColor = System::Drawing::Color::Gainsboro;
			this->iconButton4->IconChar = FontAwesome::Sharp::IconChar::PowerOff;
			this->iconButton4->IconColor = System::Drawing::Color::Gainsboro;
			this->iconButton4->IconSize = 40;
			this->iconButton4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->iconButton4->Location = System::Drawing::Point(0, 415);
			this->iconButton4->Name = L"iconButton4";
			this->iconButton4->Rotation = 0;
			this->iconButton4->Size = System::Drawing::Size(242, 72);
			this->iconButton4->TabIndex = 5;
			this->iconButton4->Text = L"Exit";
			this->iconButton4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->iconButton4->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->iconButton4->UseVisualStyleBackColor = false;
			this->iconButton4->Click += gcnew System::EventHandler(this, &MainForm::iconButton4_Click);
			this->iconButton4->MouseEnter += gcnew System::EventHandler(this, &MainForm::iconButton_MouseEnter);
			this->iconButton4->MouseLeave += gcnew System::EventHandler(this, &MainForm::iconButton_MouseLeave);
			// 
			// iconButton3
			// 
			this->iconButton3->BackColor = System::Drawing::Color::Transparent;
			this->iconButton3->Dock = System::Windows::Forms::DockStyle::Top;
			this->iconButton3->FlatAppearance->BorderSize = 0;
			this->iconButton3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->iconButton3->Flip = FontAwesome::Sharp::FlipOrientation::Normal;
			this->iconButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->iconButton3->ForeColor = System::Drawing::Color::Gainsboro;
			this->iconButton3->IconChar = FontAwesome::Sharp::IconChar::ChartBar;
			this->iconButton3->IconColor = System::Drawing::Color::Gainsboro;
			this->iconButton3->IconSize = 40;
			this->iconButton3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->iconButton3->Location = System::Drawing::Point(0, 327);
			this->iconButton3->Name = L"iconButton3";
			this->iconButton3->Rotation = 0;
			this->iconButton3->Size = System::Drawing::Size(242, 82);
			this->iconButton3->TabIndex = 4;
			this->iconButton3->Text = L"My progres";
			this->iconButton3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->iconButton3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->iconButton3->UseVisualStyleBackColor = false;
			this->iconButton3->Click += gcnew System::EventHandler(this, &MainForm::iconButton3_Click);
			this->iconButton3->MouseEnter += gcnew System::EventHandler(this, &MainForm::iconButton_MouseEnter);
			this->iconButton3->MouseLeave += gcnew System::EventHandler(this, &MainForm::iconButton_MouseLeave);
			// 
			// iconButton1
			// 
			this->iconButton1->BackColor = System::Drawing::Color::Transparent;
			this->iconButton1->Dock = System::Windows::Forms::DockStyle::Top;
			this->iconButton1->FlatAppearance->BorderSize = 0;
			this->iconButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->iconButton1->Flip = FontAwesome::Sharp::FlipOrientation::Normal;
			this->iconButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->iconButton1->ForeColor = System::Drawing::Color::Gainsboro;
			this->iconButton1->IconChar = FontAwesome::Sharp::IconChar::Dumbbell;
			this->iconButton1->IconColor = System::Drawing::Color::Gainsboro;
			this->iconButton1->IconSize = 40;
			this->iconButton1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->iconButton1->Location = System::Drawing::Point(0, 245);
			this->iconButton1->Name = L"iconButton1";
			this->iconButton1->Rotation = 0;
			this->iconButton1->Size = System::Drawing::Size(242, 82);
			this->iconButton1->TabIndex = 3;
			this->iconButton1->Text = L"Training";
			this->iconButton1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->iconButton1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->iconButton1->UseVisualStyleBackColor = false;
			this->iconButton1->Click += gcnew System::EventHandler(this, &MainForm::iconButton1_Click);
			this->iconButton1->MouseEnter += gcnew System::EventHandler(this, &MainForm::iconButton_MouseEnter);
			this->iconButton1->MouseLeave += gcnew System::EventHandler(this, &MainForm::iconButton_MouseLeave);
			// 
			// iconButton2
			// 
			this->iconButton2->BackColor = System::Drawing::Color::Transparent;
			this->iconButton2->Dock = System::Windows::Forms::DockStyle::Top;
			this->iconButton2->FlatAppearance->BorderSize = 0;
			this->iconButton2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->iconButton2->Flip = FontAwesome::Sharp::FlipOrientation::Normal;
			this->iconButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->iconButton2->ForeColor = System::Drawing::Color::Gainsboro;
			this->iconButton2->IconChar = FontAwesome::Sharp::IconChar::UserCircle;
			this->iconButton2->IconColor = System::Drawing::Color::Gainsboro;
			this->iconButton2->IconSize = 40;
			this->iconButton2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->iconButton2->Location = System::Drawing::Point(0, 163);
			this->iconButton2->Name = L"iconButton2";
			this->iconButton2->Rotation = 0;
			this->iconButton2->Size = System::Drawing::Size(242, 82);
			this->iconButton2->TabIndex = 2;
			this->iconButton2->Text = L"Profile";
			this->iconButton2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->iconButton2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->iconButton2->UseVisualStyleBackColor = false;
			this->iconButton2->Click += gcnew System::EventHandler(this, &MainForm::iconButton2_Click);
			this->iconButton2->MouseEnter += gcnew System::EventHandler(this, &MainForm::iconButton_MouseEnter);
			this->iconButton2->MouseLeave += gcnew System::EventHandler(this, &MainForm::iconButton_MouseLeave);
			// 
			// iconic
			// 
			this->iconic->BackColor = System::Drawing::Color::Transparent;
			this->iconic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"iconic.BackgroundImage")));
			this->iconic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->iconic->Dock = System::Windows::Forms::DockStyle::Top;
			this->iconic->Location = System::Drawing::Point(0, 0);
			this->iconic->Name = L"iconic";
			this->iconic->Size = System::Drawing::Size(242, 163);
			this->iconic->TabIndex = 0;
			this->iconic->TabStop = false;
			// 
			// panelheader
			// 
			this->panelheader->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->panelheader->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelheader->Controls->Add(this->iconButton7);
			this->panelheader->Controls->Add(this->label4);
			this->panelheader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelheader->Location = System::Drawing::Point(242, 0);
			this->panelheader->Name = L"panelheader";
			this->panelheader->Size = System::Drawing::Size(617, 53);
			this->panelheader->TabIndex = 1;
			this->panelheader->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panelheader_Paint);
			this->panelheader->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panelheader_MouseDown);
			this->panelheader->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panelheader_MouseMove);
			this->panelheader->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panelheader_MouseUp);
			// 
			// iconButton7
			// 
			this->iconButton7->BackColor = System::Drawing::Color::Transparent;
			this->iconButton7->FlatAppearance->BorderSize = 0;
			this->iconButton7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->iconButton7->Flip = FontAwesome::Sharp::FlipOrientation::Normal;
			this->iconButton7->ForeColor = System::Drawing::SystemColors::ControlText;
			this->iconButton7->IconChar = FontAwesome::Sharp::IconChar::SignOutAlt;
			this->iconButton7->IconColor = System::Drawing::Color::Gainsboro;
			this->iconButton7->IconSize = 40;
			this->iconButton7->Location = System::Drawing::Point(529, 8);
			this->iconButton7->Name = L"iconButton7";
			this->iconButton7->Rotation = 0;
			this->iconButton7->Size = System::Drawing::Size(75, 38);
			this->iconButton7->TabIndex = 1;
			this->iconButton7->UseVisualStyleBackColor = false;
			this->iconButton7->Visible = false;
			this->iconButton7->Click += gcnew System::EventHandler(this, &MainForm::iconButton7_Click);
			this->iconButton7->MouseEnter += gcnew System::EventHandler(this, &MainForm::iconButton_MouseEnter);
			this->iconButton7->MouseLeave += gcnew System::EventHandler(this, &MainForm::iconButton_MouseLeave);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Orange;
			this->label4->Location = System::Drawing::Point(267, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 16);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Clock";
			this->label4->Click += gcnew System::EventHandler(this, &MainForm::label4_Click_1);
			// 
			// panelmain
			// 
			this->panelmain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panelmain->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelmain->Controls->Add(this->panel1);
			this->panelmain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelmain->Location = System::Drawing::Point(242, 53);
			this->panelmain->Name = L"panelmain";
			this->panelmain->Size = System::Drawing::Size(617, 434);
			this->panelmain->TabIndex = 2;
			this->panelmain->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panelmain_Paint);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->iconButton6);
			this->panel1->Controls->Add(this->iconButton5);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(181, 32);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(259, 332);
			this->panel1->TabIndex = 10;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel1_Paint);
			// 
			// iconButton6
			// 
			this->iconButton6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->iconButton6->FlatAppearance->BorderSize = 0;
			this->iconButton6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->iconButton6->Flip = FontAwesome::Sharp::FlipOrientation::Normal;
			this->iconButton6->IconChar = FontAwesome::Sharp::IconChar::Eye;
			this->iconButton6->IconColor = System::Drawing::Color::Gainsboro;
			this->iconButton6->IconSize = 16;
			this->iconButton6->Location = System::Drawing::Point(195, 205);
			this->iconButton6->Name = L"iconButton6";
			this->iconButton6->Rotation = 0;
			this->iconButton6->Size = System::Drawing::Size(23, 22);
			this->iconButton6->TabIndex = 9;
			this->iconButton6->UseVisualStyleBackColor = false;
			this->iconButton6->Click += gcnew System::EventHandler(this, &MainForm::iconButton6_Click);
			// 
			// iconButton5
			// 
			this->iconButton5->BackColor = System::Drawing::Color::Transparent;
			this->iconButton5->Enabled = false;
			this->iconButton5->FlatAppearance->BorderSize = 0;
			this->iconButton5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->iconButton5->Flip = FontAwesome::Sharp::FlipOrientation::Normal;
			this->iconButton5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->iconButton5->IconChar = FontAwesome::Sharp::IconChar::User;
			this->iconButton5->IconColor = System::Drawing::Color::Orange;
			this->iconButton5->IconSize = 50;
			this->iconButton5->Location = System::Drawing::Point(72, 26);
			this->iconButton5->Name = L"iconButton5";
			this->iconButton5->Rotation = 0;
			this->iconButton5->Size = System::Drawing::Size(122, 86);
			this->iconButton5->TabIndex = 1;
			this->iconButton5->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Orange;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(143, 261);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 28);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Log in";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(60, 138);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(158, 22);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(61, 261);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 28);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Sign up";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->ForeColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(60, 205);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(140, 22);
			this->textBox2->TabIndex = 3;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Gainsboro;
			this->label3->Location = System::Drawing::Point(57, 236);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 16);
			this->label3->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Gainsboro;
			this->label1->Location = System::Drawing::Point(57, 115);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Gainsboro;
			this->label2->Location = System::Drawing::Point(57, 182);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Password";
			// 
			// timerClock
			// 
			this->timerClock->Interval = 1000;
			this->timerClock->Tick += gcnew System::EventHandler(this, &MainForm::timerClock_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(859, 487);
			this->Controls->Add(this->panelmain);
			this->Controls->Add(this->panelheader);
			this->Controls->Add(this->panelmenu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panelmenu->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->iconic))->EndInit();
			this->panelheader->ResumeLayout(false);
			this->panelheader->PerformLayout();
			this->panelmain->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		timerClock->Start();
		label4->Text = DateTime::Now.ToString("HH:mm:ss");
		CenterClock();
	}

	private: System::Void timerClock_Tick(System::Object^ sender, System::EventArgs^ e) {
		label4->Text = DateTime::Now.ToString("HH:mm:ss");
		CenterClock();
	}

	private: System::Void iconButton2_Click(System::Object^ sender, System::EventArgs^ e) {
		ActivateButton(sender);
		/*panelmain->Controls->Clear();
		Profile_form^ f2 = gcnew Profile_form(LoggedInUser);
		f2->TopLevel = false;
		f2->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		f2->Dock = System::Windows::Forms::DockStyle::Fill;
		panelmain->Controls->Add(f2);
		f2->Show();*/
	}

	private: System::Void iconButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		ActivateButton(sender);
		/*panelmain->Controls->Clear();
		Trainigform^ f1 = gcnew Trainigform(LoggedInUser);
		f1->TopLevel = false;
		f1->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		f1->Dock = System::Windows::Forms::DockStyle::Fill;
		panelmain->Controls->Add(f1);
		f1->Show();*/
	}

	private: System::Void iconButton3_Click(System::Object^ sender, System::EventArgs^ e) {
		ActivateButton(sender);
		/*panelmain->Controls->Clear();
		ProgressForm^ f3 = gcnew ProgressForm(LoggedInUser);
		f3->TopLevel = false;
		f3->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		f3->Dock = System::Windows::Forms::DockStyle::Fill;
		panelmain->Controls->Add(f3);
		f3->Show();*/
	}

	private: System::Void iconButton4_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ login = textBox1->Text->Trim();
		String^ password = textBox2->Text->Trim();

		if (String::IsNullOrEmpty(login) || String::IsNullOrEmpty(password)) {
			label3->ForeColor = System::Drawing::Color::Red;
			label3->Text = "Enter login and password";
			return;
		}

		if (AuthService::Login(login, password)) {
			label3->ForeColor = System::Drawing::Color::Lime;
			label3->Text = "Login successful";
			LoggedInUser = login;

			UnlockMenu();
			panel1->Visible = false;
			ActivateButton(iconButton2);
			panelmain->Controls->Clear();
			/*Profile_form^ f2 = gcnew Profile_form(LoggedInUser);
			f2->TopLevel = false;
			f2->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			f2->Dock = System::Windows::Forms::DockStyle::Fill;
			panelmain->Controls->Add(f2);
			f2->Show();*/
			iconButton7->Visible = true;
		}
		else {
			label3->ForeColor = System::Drawing::Color::Red;
			label3->Text = "Incorrect login or password";
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ login = textBox1->Text->Trim();
		String^ password = textBox2->Text->Trim();

		if (String::IsNullOrEmpty(login) || String::IsNullOrEmpty(password)) {
			label3->ForeColor = System::Drawing::Color::Red;
			label3->Text = "Enter login and password";
			return;
		}

		if (AuthService::SignUp(login, password)) {
			label3->ForeColor = System::Drawing::Color::Lime;
			label3->Text = "User added";
			textBox1->Clear();
			textBox2->Clear();
		}
		else {
			label3->ForeColor = System::Drawing::Color::Red;
			label3->Text = "Login already exists";
		}
	}

	private: System::Void iconButton7_Click(System::Object^ sender, System::EventArgs^ e) {
		LoggedInUser = "";
		LockMenu();
		DisableButton();

		panelmain->Controls->Clear();
		panelmain->Controls->Add(this->panel1);
		panel1->Visible = true;

		textBox1->Clear();
		textBox2->Clear();
		label3->Text = "";
		textBox2->UseSystemPasswordChar = true;
		iconButton6->IconChar = FontAwesome::Sharp::IconChar::Eye;
		iconButton7->Visible = false;
	}

	private: System::Void iconButton6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->UseSystemPasswordChar) {
			textBox2->UseSystemPasswordChar = false;
			iconButton6->IconChar = FontAwesome::Sharp::IconChar::Eye;
		}
		else {
			textBox2->UseSystemPasswordChar = true;
			iconButton6->IconChar = FontAwesome::Sharp::IconChar::EyeSlash;
		}
	}

	private: System::Void panelheader_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		dragCursorPoint = Cursor->Position;
		dragFormPoint = this->Location;
	}

	private: System::Void panelheader_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point diff = Point(Cursor->Position.X - dragCursorPoint.X, Cursor->Position.Y - dragCursorPoint.Y);
			this->Location = Point(dragFormPoint.X + diff.X, dragFormPoint.Y + diff.Y);
		}
	}

	private: System::Void panelheader_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}

	private: System::Void iconButton_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		IconButton^ btn = dynamic_cast<IconButton^>(sender);
		if (btn != nullptr && btn->Enabled) {
			btn->BackColor = System::Drawing::Color::FromArgb(45, 45, 48);
		}
	}

	private: System::Void iconButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		IconButton^ btn = dynamic_cast<IconButton^>(sender);
		if (btn != nullptr && btn->Enabled) {
			btn->BackColor = System::Drawing::Color::Transparent;
		}
	}

	private: System::Void panelmain_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	private: System::Void panelheader_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label4_Click_1(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	};
}