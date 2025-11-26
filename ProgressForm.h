#pragma once
#include "Services.h"

namespace BeonFit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	public ref class ProgressForm : public System::Windows::Forms::Form
	{
	public:
		ProgressForm(String^ login)
		{
			InitializeComponent();
			userLogin = login;
			showCalories = true;
		}

	protected:
		~ProgressForm()
		{
			if (components) delete components;
		}

	private:
		String^ userLogin;
		bool showCalories;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// chart1
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Top;
			legend1->Alignment = System::Drawing::StringAlignment::Center;
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Bright;
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(617, 200);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &ProgressForm::chart1_Click);
			this->chart1->Cursor = System::Windows::Forms::Cursors::Hand;
			// chart2
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			this->chart2->Dock = System::Windows::Forms::DockStyle::Fill;
			legend2->Alignment = System::Drawing::StringAlignment::Center;
			legend2->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(0, 200);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(617, 213);
			this->chart2->TabIndex = 1;
			this->chart2->Text = L"chart2";
			// ProgressForm
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(617, 413);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ProgressForm";
			this->Text = L"ProgressForm";
			this->Load += gcnew System::EventHandler(this, &ProgressForm::ProgressForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion

	private: void LoadCaloriesChart()
	{
		OdbcConnection^ conn = DbHelper::GetConnection();
		try {
			conn->Open();
			OdbcDataReader^ reader = StatsService::GetChartData(conn, "\"Calories_burned\"");

			chart1->Series->Clear();
			chart1->ChartAreas[0]->AxisY->Minimum = Double::NaN;
			chart1->ChartAreas[0]->AxisY->Maximum = Double::NaN;
			chart1->ChartAreas[0]->RecalculateAxesScale();
			chart1->ChartAreas[0]->AxisY->Title = "Kcal";
			chart1->ChartAreas[0]->AxisY->IsStartedFromZero = true;

			// Стилізація під темну тему
			chart1->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
			chart1->ChartAreas[0]->BackColor = System::Drawing::Color::FromArgb(40, 40, 40);
			chart1->ChartAreas[0]->AxisX->LabelStyle->ForeColor = System::Drawing::Color::White;
			chart1->ChartAreas[0]->AxisY->LabelStyle->ForeColor = System::Drawing::Color::White;
			chart1->ChartAreas[0]->AxisY->TitleForeColor = System::Drawing::Color::White;
			chart1->Legends[0]->BackColor = System::Drawing::Color::Transparent;
			chart1->Legends[0]->ForeColor = System::Drawing::Color::White;

			Series^ calSeries = gcnew Series("Calories Burned");
			calSeries->ChartType = SeriesChartType::Line;
			calSeries->BorderWidth = 3;
			calSeries->Color = System::Drawing::Color::Orange;
			calSeries->MarkerStyle = MarkerStyle::Circle;
			calSeries->MarkerSize = 8;

			while (reader->Read()) {
				if (reader["Calories_burned"] != DBNull::Value) {
					DateTime date = DateTime::Parse(reader["Data"]->ToString());
					int cal = Convert::ToInt32(reader["Calories_burned"]);
					calSeries->Points->AddXY(date.ToShortDateString(), cal);
				}
			}
			chart1->Series->Add(calSeries);
			reader->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error Calories: " + ex->Message);
		}
		finally {
			conn->Close();
		}
	}

	private: void LoadWeightChart()
	{
		OdbcConnection^ conn = DbHelper::GetConnection();
		try {
			conn->Open();
			OdbcDataReader^ reader = StatsService::GetChartData(conn, "\"Weight\"");

			chart1->Series->Clear();
			chart1->ChartAreas[0]->AxisY->Minimum = Double::NaN;
			chart1->ChartAreas[0]->AxisY->Maximum = Double::NaN;
			chart1->ChartAreas[0]->RecalculateAxesScale();
			chart1->ChartAreas[0]->AxisY->Title = "Kg";
			chart1->ChartAreas[0]->AxisY->IsStartedFromZero = false;

			// Стилізація
			chart1->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
			chart1->ChartAreas[0]->BackColor = System::Drawing::Color::FromArgb(40, 40, 40);
			chart1->ChartAreas[0]->AxisX->LabelStyle->ForeColor = System::Drawing::Color::White;
			chart1->ChartAreas[0]->AxisY->LabelStyle->ForeColor = System::Drawing::Color::White;
			chart1->ChartAreas[0]->AxisY->TitleForeColor = System::Drawing::Color::White;
			chart1->Legends[0]->BackColor = System::Drawing::Color::Transparent;
			chart1->Legends[0]->ForeColor = System::Drawing::Color::White;

			Series^ weightSeries = gcnew Series("Weight (kg)");
			weightSeries->ChartType = SeriesChartType::Line;
			weightSeries->BorderWidth = 3;
			weightSeries->Color = System::Drawing::Color::Cyan;
			weightSeries->MarkerStyle = MarkerStyle::Circle;
			weightSeries->MarkerSize = 8;

			while (reader->Read()) {
				if (reader["Weight"] != DBNull::Value) {
					DateTime date = DateTime::Parse(reader["Data"]->ToString());
					double w = Convert::ToDouble(reader["Weight"]);
					if (w > 0) {
						weightSeries->Points->AddXY(date.ToShortDateString(), w);
					}
				}
			}
			chart1->Series->Add(weightSeries);
			reader->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error Weight: " + ex->Message);
		}
		finally {
			conn->Close();
		}
	}

	private: void LoadBodyMeasurementsChart()
	{
		OdbcConnection^ conn = DbHelper::GetConnection();
		try
		{
			conn->Open();
			OdbcDataReader^ reader = StatsService::GetChartData(conn, "\"Chest_size\", \"Back_size\", \"Leg_size\", \"Arm_size\"");

			chart2->Series->Clear();
			chart2->ChartAreas[0]->AxisY->IsStartedFromZero = false;
			chart2->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
			chart2->ChartAreas[0]->BackColor = System::Drawing::Color::FromArgb(40, 40, 40);
			chart2->ChartAreas[0]->AxisX->LabelStyle->ForeColor = System::Drawing::Color::White;
			chart2->ChartAreas[0]->AxisY->LabelStyle->ForeColor = System::Drawing::Color::White;
			chart2->ChartAreas[0]->AxisY->TitleForeColor = System::Drawing::Color::White;
			chart2->Legends[0]->BackColor = System::Drawing::Color::Transparent;
			chart2->Legends[0]->ForeColor = System::Drawing::Color::White;
			chart2->Legends[0]->Docking = Docking::Top;

			Series^ chestSeries = gcnew Series("Chest"); chestSeries->ChartType = SeriesChartType::Line; chestSeries->BorderWidth = 2; chestSeries->Color = System::Drawing::Color::LimeGreen; chestSeries->MarkerStyle = MarkerStyle::Circle; chestSeries->MarkerSize = 7;
			Series^ backSeries = gcnew Series("Back"); backSeries->ChartType = SeriesChartType::Line; backSeries->BorderWidth = 2; backSeries->Color = System::Drawing::Color::DeepSkyBlue; backSeries->MarkerStyle = MarkerStyle::Circle; backSeries->MarkerSize = 7;
			Series^ legSeries = gcnew Series("Leg"); legSeries->ChartType = SeriesChartType::Line; legSeries->BorderWidth = 2; legSeries->Color = System::Drawing::Color::Gold; legSeries->MarkerStyle = MarkerStyle::Circle; legSeries->MarkerSize = 7;
			Series^ armSeries = gcnew Series("Arm"); armSeries->ChartType = SeriesChartType::Line; armSeries->BorderWidth = 2; armSeries->Color = System::Drawing::Color::HotPink; armSeries->MarkerStyle = MarkerStyle::Circle; armSeries->MarkerSize = 7;

			while (reader->Read())
			{
				DateTime date = DateTime::Parse(reader["Data"]->ToString());
				int chest = reader["Chest_size"] != DBNull::Value ? Convert::ToInt32(reader["Chest_size"]) : 0;
				int back = reader["Back_size"] != DBNull::Value ? Convert::ToInt32(reader["Back_size"]) : 0;
				int leg = reader["Leg_size"] != DBNull::Value ? Convert::ToInt32(reader["Leg_size"]) : 0;
				int arm = reader["Arm_size"] != DBNull::Value ? Convert::ToInt32(reader["Arm_size"]) : 0;
				chestSeries->Points->AddXY(date.ToShortDateString(), chest);
				backSeries->Points->AddXY(date.ToShortDateString(), back);
				legSeries->Points->AddXY(date.ToShortDateString(), leg);
				armSeries->Points->AddXY(date.ToShortDateString(), arm);
			}

			chart2->Series->Add(chestSeries);
			chart2->Series->Add(backSeries);
			chart2->Series->Add(legSeries);
			chart2->Series->Add(armSeries);
			chart2->ChartAreas[0]->AxisY->Title = "Size (cm)";
			reader->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error Chart 2: " + ex->Message);
		}
		finally {
			conn->Close();
		}
	}

	private: System::Void ProgressForm_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadCaloriesChart();
		LoadBodyMeasurementsChart();
	}

	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
		showCalories = !showCalories;
		if (showCalories) LoadCaloriesChart();
		else LoadWeightChart();
	}
	};
}