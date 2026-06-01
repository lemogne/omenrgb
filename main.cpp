#include "omenrgb.cpp"
#include "omenlib.hpp"
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


class main_frame : public MyFrame1 {
	std::vector<std::string> configurations;
	std::vector<std::array<std::string, 4>> palettes;
	int current_palette = -1;
	
	public:
	main_frame() : MyFrame1(nullptr) {
		std::vector<int> zone00 = read_device("zone00");
		std::vector<int> zone01 = read_device("zone01");
		std::vector<int> zone02 = read_device("zone02");
		std::vector<int> zone03 = read_device("zone03");

		set_zones(zone00, zone01, zone02, zone03);
		load_palettes();
	}
	
	
	void set_zones(std::vector<int> zone00, std::vector<int> zone01, std::vector<int> zone02, std::vector<int> zone03) {
		m_colourPicker1->SetColour(wxColour(zone00[0], zone00[1], zone00[2]));
		m_colourPicker2->SetColour(wxColour(zone01[0], zone01[1], zone01[2]));
		m_colourPicker3->SetColour(wxColour(zone02[0], zone02[1], zone02[2]));
		m_colourPicker4->SetColour(wxColour(zone03[0], zone03[1], zone03[2]));
	}
	
	
	std::array<std::string, 4> get_zones() {
		std::array<std::string, 4> current_palette;
		
		current_palette[0] = colour_as_hex(m_colourPicker1->GetColour());
		current_palette[1] = colour_as_hex(m_colourPicker2->GetColour());
		current_palette[2] = colour_as_hex(m_colourPicker3->GetColour());
		current_palette[3] = colour_as_hex(m_colourPicker4->GetColour());
		
		return current_palette;
	}
	

	virtual void zone00_change(wxColourPickerEvent& event) {
		omenlib::set_color(0, colour_as_hex(event.GetColour()));
		
		if (current_palette == 0)
			palettes[0] = get_zones();
	}
	virtual void zone01_change(wxColourPickerEvent& event) {
		omenlib::set_color(1, colour_as_hex(event.GetColour()));
		
		if (current_palette == 0)
			palettes[0] = get_zones();
	}
	virtual void zone02_change(wxColourPickerEvent& event) {
		omenlib::set_color(2, colour_as_hex(event.GetColour()));
		
		if (current_palette == 0)
			palettes[0] = get_zones();
	}
	virtual void zone03_change(wxColourPickerEvent& event) {
		omenlib::set_color(3, colour_as_hex(event.GetColour()));
		
		if (current_palette == 0)
			palettes[0] = get_zones();
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
	
	
	void load_palettes() {
		std::string home = getenv("HOME");
		std::ifstream file;
		open_file(file, home + "/.config/omenrgb.cfg");
		
		if (!file)
			return;
		
		std::string line;
		
		m_palettes->Append("Custom");
		configurations.push_back("Custom");
		palettes.push_back(get_zones());
		m_palettes->SetSelection(0);
		
		while (std::getline(file, line)) {
			std::string name;
			std::array<std::string, 4> colors;
			std::stringstream ss(line);
			
			std::getline(ss, name, '\t');
			
			for (int i = 0; i < 4; i++) 
				std::getline(ss, colors[i], '\t');
			
			m_palettes->Append(name);
			configurations.push_back(name);
			palettes.push_back(colors);
		}
		
		file.close();
	}


	void apply(wxCommandEvent& event) {
		current_palette = m_palettes->GetSelection();
		
		if (current_palette == wxNOT_FOUND) {
			current_palette = -1;
			return;
		}
		
		set_zones(
			fromhex(palettes[current_palette][0]), 
			fromhex(palettes[current_palette][1]), 
			fromhex(palettes[current_palette][2]), 
			fromhex(palettes[current_palette][3])
		);
		
		omenlib::set_color(0, palettes[current_palette][0]);
		omenlib::set_color(1, palettes[current_palette][1]);
		omenlib::set_color(2, palettes[current_palette][2]);
		omenlib::set_color(3, palettes[current_palette][3]);
	}


	void change(wxCommandEvent& event) {
		main_frame* parent = (main_frame*) GetParent();
		current_palette = m_palettes->GetSelection();
		
		if (current_palette == wxNOT_FOUND) {
			current_palette = -1;
			return;
		} else if (current_palette == 0) {
			palettes[0] = get_zones();
			return;
		}
		
		std::string palette = configurations[current_palette];
		wxMessageDialog dialog(NULL, "Do you really want to modify the palette '" + palette +"'?", "Modify Palette...", wxYES_NO | wxICON_QUESTION);

		if (dialog.ShowModal() == wxID_YES)
			palettes[current_palette] = get_zones();
	}


	void add(wxCommandEvent& event) {
		TextEntryDialog dialog(this);
		if (dialog.ShowModal() == wxID_OK) {
			wxString name = dialog.m_name->GetLineText(0);
			configurations.push_back(name.ToStdString());
			m_palettes->Append(name);
			
			main_frame* parent = (main_frame*) GetParent();
			palettes.push_back(get_zones());
			
			m_palettes->SetSelection(palettes.size() - 1);
		}
	}


	void remove(wxCommandEvent& event) {
		current_palette = m_palettes->GetSelection();
		
		if (current_palette == wxNOT_FOUND) {
			current_palette = -1;
			return;
		}
		
		std::string palette = configurations[current_palette];
		
		wxMessageDialog dialog(NULL, "Do you really want to remove the palette '" + palette +"'?", "Remove Palette...", wxYES_NO | wxICON_QUESTION);
		
		if (dialog.ShowModal() == wxID_YES) {
			m_palettes->Delete(current_palette);
			configurations.erase(configurations.begin() + current_palette);
			palettes.erase(palettes.begin() + current_palette);
			current_palette = -1;
		}
	}
	

	void save_config() {
		std::string home = getenv("HOME");
		std::ofstream file;
		open_file(file, home + "/.config/omenrgb.cfg");
		
		if (!file) {
			std::cerr << "Could not open config file!\n";
			return;
		}
			
		for (int i = 1; i < palettes.size(); i++) {
			file << configurations[i];
			for (int j = 0; j < 4; j++)
				file << '\t' << palettes[i][j];
			
			file << '\n'; 
		}
		
		file.close();
	}
};


bool OmenRGB::OnInit() {
	omenlib::init();
	main_frame* frame = new main_frame();
	frame->ShowModal();
	frame->save_config();
	Exit();
	omenlib::deinit();
	return true;
}
