#include "omenrgb.cpp"
#include <wx/app.h> 
#include <wx/msgdlg.h>
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


std::string colour_as_hex(wxColour colour) {
	return tohex(colour.Red()) + tohex(colour.Green()) + tohex(colour.Blue());
}

std::vector<int> fromhex(std::string hex) {
	std::vector<int> output;

	for (int i = 0; i < hex.length() / 2; i++) {
		int res = std::stoi(hex.substr(2 * i, 2), nullptr, 16);
		output.push_back(res);
	}
	
	return output;
}

class main_frame;

class preset_frame : public PresetDialog {
	std::vector<std::string> configurations;
	std::vector<std::array<std::string, 4>> presets;
	int current_preset = -1;
	
	public:
	preset_frame(main_frame* parent);
	
	void apply(wxCommandEvent& event);
	void change(wxCommandEvent& event);
	void add(wxCommandEvent& event);
	void remove(wxCommandEvent& event);
	~preset_frame();
};


class main_frame : public MyFrame1 {
	public:
	main_frame() : MyFrame1(nullptr) {
		std::vector<int> zone00 = read_device("zone00");
		std::vector<int> zone01 = read_device("zone01");
		std::vector<int> zone02 = read_device("zone02");
		std::vector<int> zone03 = read_device("zone03");

		set_zones(zone00, zone01, zone02, zone03);
	}
	
	
	void set_zones(std::vector<int> zone00, std::vector<int> zone01, std::vector<int> zone02, std::vector<int> zone03) {
		m_colourPicker1->SetColour(wxColour(zone00[0], zone00[1], zone00[2]));
		m_colourPicker2->SetColour(wxColour(zone01[0], zone01[1], zone01[2]));
		m_colourPicker3->SetColour(wxColour(zone02[0], zone02[1], zone02[2]));
		m_colourPicker4->SetColour(wxColour(zone03[0], zone03[1], zone03[2]));
	}
	
	
	std::array<std::string, 4> get_zones() {
		std::array<std::string, 4> current_preset;
		
		current_preset[0] = colour_as_hex(m_colourPicker1->GetColour());
		current_preset[1] = colour_as_hex(m_colourPicker2->GetColour());
		current_preset[2] = colour_as_hex(m_colourPicker3->GetColour());
		current_preset[3] = colour_as_hex(m_colourPicker4->GetColour());
		
		return current_preset;
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
		write_device(dev, colour_as_hex(colour));
	}
	

	void write_device(std::string dev, std::string colour) {
		std::ofstream zone;
		
		if (open_file(zone, "/sys/devices/platform/hp-wmi/rgb_zones/" + dev))
			return;
		
		zone << colour;
		zone.close();
	}
	
	
	virtual void open_presets(wxCommandEvent& event) {
		preset_frame frame(this);
		frame.ShowModal();
	}
};


preset_frame::preset_frame(main_frame* parent) : PresetDialog(parent) {
	// Load presets from file
	std::string home = getenv("HOME");
	std::ifstream file;
	parent->open_file(file, home + "/.config/omenrgb.cfg");
	
	if (!file)
		return;
	
	std::string line;
	
	while (std::getline(file, line)) {
		std::string name;
		std::array<std::string, 4> colors;
		std::stringstream ss(line);
		
		std::getline(ss, name, '\t');
		
		for (int i = 0; i < 4; i++) 
			std::getline(ss, colors[i], '\t');
		
		m_preset->Append(name);
		configurations.push_back(name);
		presets.push_back(colors);
	}
	
	file.close();
}


void preset_frame::apply(wxCommandEvent& event) {
	main_frame* parent = (main_frame*) GetParent();
	
	current_preset = m_preset->GetSelection();
	
	if (current_preset == wxNOT_FOUND) {
		current_preset = -1;
		return;
	}
	
	parent->set_zones(
		fromhex(presets[current_preset][0]), 
		fromhex(presets[current_preset][1]), 
		fromhex(presets[current_preset][2]), 
		fromhex(presets[current_preset][3])
	);
	
	parent->write_device("zone00", presets[current_preset][0]);
	parent->write_device("zone01", presets[current_preset][1]);
	parent->write_device("zone02", presets[current_preset][2]);
	parent->write_device("zone03", presets[current_preset][3]);
}


void preset_frame::change(wxCommandEvent& event) {
	main_frame* parent = (main_frame*) GetParent();
	current_preset = m_preset->GetSelection();
	
	if (current_preset == wxNOT_FOUND) {
		current_preset = -1;
		return;
	}
	
	std::string preset = configurations[current_preset];
	wxMessageDialog dialog(NULL, "Do you really want to modify the preset '" + preset +"'?", "Modify Preset...", wxYES_NO | wxICON_QUESTION);

	if (dialog.ShowModal() == wxID_YES)
		presets[current_preset] = parent->get_zones();
}


void preset_frame::add(wxCommandEvent& event) {
	TextEntryDialog dialog(this);
	if (dialog.ShowModal() == wxID_OK) {
		wxString name = dialog.m_name->GetLineText(0);
		configurations.push_back(name.ToStdString());
		m_preset->Append(name);
		
		main_frame* parent = (main_frame*) GetParent();
		presets.push_back(parent->get_zones());
	}
}


void preset_frame::remove(wxCommandEvent& event) {
	main_frame* parent = (main_frame*) GetParent();
	current_preset = m_preset->GetSelection();
	
	if (current_preset == wxNOT_FOUND) {
		current_preset = -1;
		return;
	}
	
	std::string preset = configurations[current_preset];
	
	wxMessageDialog dialog(NULL, "Do you really want to remove the preset '" + preset +"'?", "Remove Preset...", wxYES_NO | wxICON_QUESTION);
	
	if (dialog.ShowModal() == wxID_YES) {
		m_preset->Delete(current_preset);
		configurations.erase(configurations.begin() + current_preset);
		presets.erase(presets.begin() + current_preset);
		current_preset = -1;
	}
}


preset_frame::~preset_frame() {
	std::string home = getenv("HOME");
	main_frame* parent = (main_frame*) GetParent();
	std::ofstream file;
	parent->open_file(file, home + "/.config/omenrgb.cfg");
	
	if (!file)
		return;
		
	for (int i = 0; i < presets.size(); i++) {
		file << configurations[i];
		for (int j = 0; j < 4; j++)
			file << '\t' << presets[i][j];
		
		file << '\n'; 
	}
	
	file.close();
}


bool OmenRGB::OnInit() {
	main_frame* frame = new main_frame();
	frame->ShowModal();
	Exit();
	return true;
}
