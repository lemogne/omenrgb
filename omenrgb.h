///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/notebook.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxDialog
{
	private:

	protected:
		wxBoxSizer* bSizer1;
		wxNotebook* m_notebook1;
		wxPanel* m_panel1;
		wxBoxSizer* bSizer7;
		wxStaticText* m_staticText10;
		wxChoice* m_palettes;
		wxButton* m_button_new;
		wxButton* m_button_delete;
		wxGridSizer* palette_sizer;
		wxBoxSizer* bSizer13;
		wxButton* m_button_set;
		wxButton* m_button_add;
		wxPanel* m_panel2;
		wxStaticText* m_staticText11;
		wxSlider* m_slider1;
		wxStaticText* m_staticText12;
		wxSlider* m_slider2;
		wxStaticText* m_staticText9;
		wxChoice* m_animations;
		wxButton* m_button_add1;
		wxButton* m_button_delete1;

		// Virtual event handlers, override them in your derived class
		virtual void apply( wxCommandEvent& event ) { event.Skip(); }
		virtual void add( wxCommandEvent& event ) { event.Skip(); }
		virtual void remove( wxCommandEvent& event ) { event.Skip(); }
		virtual void save_config( wxCommandEvent& event ) { event.Skip(); }
		virtual void add_palette_color_event( wxCommandEvent& event ) { event.Skip(); }
		virtual void set_speed( wxScrollEvent& event ) { event.Skip(); }
		virtual void set_speed( wxCommandEvent& event ) { event.Skip(); }
		virtual void set_brightness( wxScrollEvent& event ) { event.Skip(); }
		virtual void set_brightness( wxCommandEvent& event ) { event.Skip(); }
		virtual void animation_change( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxStaticText* m_status;

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("OMEN RGB"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxDIALOG_NO_PARENT );

		~MyFrame1();

};

///////////////////////////////////////////////////////////////////////////////
/// Class TextEntryDialog
///////////////////////////////////////////////////////////////////////////////
class TextEntryDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText11;
		wxStdDialogButtonSizer* m_sdbSizer2;
		wxButton* m_sdbSizer2OK;
		wxButton* m_sdbSizer2Cancel;

	public:
		wxTextCtrl* m_name;

		TextEntryDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add New Preset..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~TextEntryDialog();

};

