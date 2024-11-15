#include "omenrgb.cpp"
#include <wx/app.h> 
#include <fstream>
#include <sstream>
#include <iostream>

class OmenRGB: public wxApp {
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(OmenRGB);

std::string tohex(unsigned char i) {
	char upper = (i >> 4) & 0xf;
	char lower = i & 0xf;
	char upper_char = (upper > 9) ? ('A' + upper - 10) : (upper + '0');
	char lower_char = (lower > 9) ? ('A' + lower - 10) : (lower + '0');
	return std::string(1, upper_char) + std::string(1, lower_char);
}

class main_frame : public MyFrame1 {
	public:
	main_frame() : MyFrame1(nullptr) {
		std::vector<int> zone00 = read_device("zone00");
		m_colourPicker1->SetColour(wxColour(zone00[0], zone00[1], zone00[2]));

		std::vector<int> zone01 = read_device("zone01");
		m_colourPicker2->SetColour(wxColour(zone01[0], zone01[1], zone01[2]));

		std::vector<int> zone02 = read_device("zone02");
		m_colourPicker3->SetColour(wxColour(zone02[0], zone02[1], zone02[2]));

		std::vector<int> zone03 = read_device("zone03");
		m_colourPicker4->SetColour(wxColour(zone03[0], zone03[1], zone03[2]));
	}

	virtual void zone00_change(wxColourPickerEvent& event) {
		write_device("zone00", event.GetColour());
	}
	virtual void zone01_change(wxColourPickerEvent& event) {
		write_device("zone01", event.GetColour());
	}
	virtual void zone02_change(wxColourPickerEvent& event) {
		write_device("zone02", event.GetColour());
	}
	virtual void zone03_change(wxColourPickerEvent& event) {
		write_device("zone03", event.GetColour());
	}

	template <typename T>
	// Opens file; returns true and prints an error message on failure
	bool open_file(T& file, std::string path) {
		file.open(path);
		if (!file) {
			std::string old_text = this->m_status->GetLabelText().ToStdString();
			this->m_status->SetLabelText((old_text + '\n' + "Could not open " + path).c_str());
			this->Layout();
			this->Update();
			return true;
		}
		return false;
	}

	std::vector<int> read_device(std::string dev) {
		std::vector<int> vec{};
		std::ifstream zone;
		std::string line;
		if (open_file(zone, "/sys/devices/platform/hp-wmi/rgb_zones/" + dev))
			return {255, 255, 255};
		std::getline(zone, line);
		int i = 0;
		bool is_num = false;
		for (char c : line) {
			switch (c) {
				case '0' ... '9':
					is_num = true;
					i *= 10;
					i += c - '0';
					continue;
				
				default:
					if (is_num) {
						vec.push_back(i);
						is_num = false;
						i = 0;
					}
					continue;
			}
		}
		if (is_num) 
			vec.push_back(i);

		zone.close();
		return vec;
	}

	void write_device(std::string dev, wxColour colour) {
		std::ofstream zone;
		std::string line = tohex(colour.Red()) + tohex(colour.Green()) + tohex(colour.Blue());
		if (open_file(zone, "/sys/devices/platform/hp-wmi/rgb_zones/" + dev))
			return;
		zone << line;
		zone.close();
	}
};

bool OmenRGB::OnInit() {
	main_frame* frame = new main_frame();
	frame->ShowModal();
	Exit();
	return true;
}
