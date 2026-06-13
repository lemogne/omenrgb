#include "omenrgb.cpp"
#include "omenlib.hpp"
#include <wx/app.h> 
#include <wx/msgdlg.h>
#include <wx/clrpicker.h>
#include <fstream>
#include <sstream>
#include <iostream>

std::string palette_cfg = "/.config/omenrgb/palettes.cfg";
std::string animation_cfg = "/.config/omenrgb/animations.cfg";
bool palettes_modified = false;

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


struct palette_color {
	wxColourPickerCtrl* ctrl;
	wxButton* del;
	
	palette_color(wxWindow* w, int id) {
		ctrl = new wxColourPickerCtrl(w, id);
		del = new wxButton(w, id, "", wxDefaultPosition, wxSize(40, -1));
		del->SetBitmap(wxArtProvider::GetBitmap(wxASCII_STR(wxART_MINUS), wxASCII_STR(wxART_BUTTON)));
	}
};


class main_frame : public MyFrame1 {
	std::vector<std::string> configurations;
	std::vector<std::vector<std::string>> palettes;
	std::vector<palette_color> palette_colors;
	int current_palette = 0;
	
	public:
	main_frame() : MyFrame1(nullptr) {
		std::vector<int> zone00 = read_device("zone00");
		std::vector<int> zone01 = read_device("zone01");
		std::vector<int> zone02 = read_device("zone02");
		std::vector<int> zone03 = read_device("zone03");

		load_palettes();
		set_palette_ctrl({zone00, zone01, zone02, zone03});
		set_palette_to_zones();
		
		load_animations();
	}
	
	
	void set_palette_to_zones() {
		for (palette_color& p : palette_colors)
			palettes[current_palette].push_back(colour_as_hex(p.ctrl->GetColour()));
	}
	
	
	void set_palette_ctrl(std::vector<std::vector<int>> zones) {
		for (int i = 0; i < zones.size(); i++) {
			wxColour color = wxColour(zones[i][0], zones[i][1], zones[i][2]);
			
			if (i >= palette_colors.size())
				add_palette_color(color);
			else
				palette_colors[i].ctrl->SetColour(color);
		}
		
		for (long i = palette_colors.size() - 1; i >= (long) zones.size(); i--) 
			remove_palette_color(i);
	}
	
	
	std::vector<std::string> get_palette_ctrl() {
		std::vector<std::string> current_palette;
		
		for (palette_color& p : palette_colors)
			current_palette.push_back(colour_as_hex(p.ctrl->GetColour()));
		
		return current_palette;
	}
	
	
	void zone_change(wxColourPickerEvent& event) {
		int id = event.GetId();
		omenlib::set_color(id, colour_as_hex(event.GetColour()));
		
		change();
	}
	
	
	virtual void animation_change(wxCommandEvent& event) {
		int animation = m_animations->GetSelection();
		
		if (animation != wxNOT_FOUND)
			omenlib::set_animation(animation);
	}
	
	
	void add_palette_color(wxColour color) {
		int id = palette_colors.size() - 1;
		palette_colors.push_back(palette_color(this->m_panel1, id));
		palette_colors.back().ctrl->SetColour(color);
		palette_colors.back().ctrl->Connect(id, wxEVT_COLOURPICKER_CHANGED, wxColourPickerEventHandler(main_frame::zone_change), NULL, this);
		
		wxColourPickerCtrl* color_picker = palette_colors.back().ctrl;
		wxButton* del_button = palette_colors.back().del;
		
		palette_sizer->Add(del_button, 0, wxALL | wxALIGN_RIGHT, 5);
		palette_sizer->Add(color_picker, 0, wxALL | wxEXPAND, 5);
		
		m_panel1->Layout();
		Fit();
	}
	
	
	void remove_palette_color(int i) {
		wxColourPickerCtrl* color_picker = palette_colors[i].ctrl;
		wxButton* del_button = palette_colors[i].del;
		
		color_picker->Disconnect(i, wxEVT_COLOURPICKER_CHANGED, wxColourPickerEventHandler(main_frame::zone_change), NULL, this);
		del_button->Destroy();
		color_picker->Destroy();
		palette_colors.erase(palette_colors.begin() + i);
		
		palette_sizer->Layout();
		m_panel1->Layout();
		m_notebook1->InvalidateBestSize();
		m_notebook1->Layout();
		Fit();
	}
	
	
	virtual void add_palette_color_event(wxCommandEvent& event) {
		palettes[current_palette].push_back("000000");
		add_palette_color(wxColour(0, 0, 0));
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
		open_file(file, home + palette_cfg);
		
		if (!file) {
			std::cerr << "Couldn't open palette config file.\n";
			return;
		}
		
		std::string line;
		
		m_palettes->Append("Custom");
		configurations.push_back("Custom");
		palettes.push_back(get_palette_ctrl());
		m_palettes->SetSelection(0);
		
		while (std::getline(file, line)) {
			std::string name;
			std::string color;
			std::vector<std::string> colors;
			std::stringstream ss(line);
			
			if (line[0] == '#' || line[0] == '\n')
				continue;
			
			std::getline(ss, name, '\t');
			
			while (std::getline(ss, color, '\t'))
				colors.push_back(color);
			
			m_palettes->Append(name);
			configurations.push_back(name);
			palettes.push_back(colors);
		}
		
		file.close();
	}


	void load_animations() {
		std::string home = getenv("HOME");
		std::ifstream file;
		open_file(file, home + animation_cfg);
		
		if (!file) {
			std::cerr << "Couldn't open animation config file.\n";
			return;
		}
		
		std::string line;
		
		m_animations->Append("None");
		m_animations->SetSelection(0);
		
		while (std::getline(file, line)) {
			std::string name;
			std::stringstream ss(line);
			
			if (line[0] != '[')
				continue;
			
			std::getline(ss, name, '\t');
			m_animations->Append(name.substr(1, name.length() - 2));
		}
		
		file.close();
	}


	void apply(wxCommandEvent& event) {
		current_palette = m_palettes->GetSelection();
		
		if (current_palette == wxNOT_FOUND) {
			current_palette = 0;
			return;
		}
		
		std::vector<std::vector<int>> palette_int;
		
		for (std::string& c : palettes[current_palette])
			palette_int.push_back(fromhex(c));
		
		set_palette_ctrl(palette_int);
		
		if (m_animations->GetSelection() == 0) {
			for (int i = 0; i < 4; i++)
				omenlib::set_color(i, palettes[current_palette][i % palettes[current_palette].size()]);
		}
		
		omenlib::set_palette(current_palette);
	}


	void change() {
		main_frame* parent = (main_frame*) GetParent();
		current_palette = m_palettes->GetSelection();
		
		if (current_palette == wxNOT_FOUND) {
			current_palette = 0;
			return;
		} else if (current_palette != 0)
			palettes_modified = true;
		
		palettes[current_palette] = get_palette_ctrl();
	}


	void add(wxCommandEvent& event) {
		TextEntryDialog dialog(this);
		if (dialog.ShowModal() == wxID_OK) {
			wxString name = dialog.m_name->GetLineText(0);
			configurations.push_back(name.ToStdString());
			m_palettes->Append(name);
			
			main_frame* parent = (main_frame*) GetParent();
			palettes.push_back(get_palette_ctrl());
			
			m_palettes->SetSelection(palettes.size() - 1);
			
			palettes_modified = true;
		}
	}


	void remove(wxCommandEvent& event) {
		current_palette = m_palettes->GetSelection();
		
		if (current_palette == wxNOT_FOUND || current_palette == 0) {
			current_palette = 0;
			return;
		}
		
		std::string palette = configurations[current_palette];
		
		wxMessageDialog dialog(NULL, "Do you really want to remove the palette '" + palette +"'?", "Remove Palette...", wxYES_NO | wxICON_QUESTION);
		
		if (dialog.ShowModal() == wxID_YES) {
			m_palettes->Delete(current_palette);
			configurations.erase(configurations.begin() + current_palette);
			palettes.erase(palettes.begin() + current_palette);
			current_palette = 0;
			palettes_modified = true;
		}
	}
	
	
	virtual void set_speed(wxScrollEvent& event) {
		float v = std::exp((m_slider1->GetValue() / 25.0f) - 2.0f);
		omenlib::set_speed(v);
	}
	
	
	virtual void set_brightness(wxScrollEvent& event) {
		float v = std::exp((m_slider2->GetValue() / 25.0f) - 2.0f);
		omenlib::set_brightness(v);
	}
	

	void save_config() {
		if (!palettes_modified)
			return;
		
		wxMessageDialog dialog(NULL, "Do you want to save your palette configuration?", "Modify Palette Config...", wxYES_NO | wxICON_QUESTION);

		if (dialog.ShowModal() != wxID_YES)
			return;
	
		std::string home = getenv("HOME");
		std::ofstream file;
		open_file(file, home + palette_cfg);
		
		if (!file) {
			std::cerr << "Could not open config file!\n";
			return;
		}
			
		for (int i = 1; i < palettes.size(); i++) {
			file << configurations[i];
			for (int j = 0; j < palettes[i].size(); j++)
				file << '\t' << palettes[i][j];
			
			file << '\n'; 
		}
		
		file.close();
		omenlib::reload_palettes();
	}
	
	
	void save_config(wxCommandEvent& event) {
		save_config();
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
