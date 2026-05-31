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
#include <wx/clrpicker.h>
#include <wx/collpane.h>
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
		wxNotebook* m_notebook1;
		wxPanel* m_panel1;
		wxStaticText* m_staticText10;
		wxChoice* m_palettes;
		wxButton* m_button_add;
		wxButton* m_button_delete;
		wxCollapsiblePane* m_collapsiblePane1;
		wxStaticText* m_staticText2;
		wxColourPickerCtrl* m_colourPicker1;
		wxStaticText* m_staticText3;
		wxColourPickerCtrl* m_colourPicker2;
		wxStaticText* m_staticText21;
		wxColourPickerCtrl* m_colourPicker3;
		wxStaticText* m_staticText31;
		wxColourPickerCtrl* m_colourPicker4;
		wxButton* m_button_set;
		wxButton* m_button10;
		wxButton* m_button101;
		wxPanel* m_panel2;
		wxStaticText* m_staticText11;
		wxSlider* m_slider1;
		wxStaticText* m_staticText9;
		wxChoice* m_choice2;
		wxButton* m_button_add1;
		wxButton* m_button_delete1;

		// Virtual event handlers, override them in your derived class
		virtual void apply( wxCommandEvent& event ) { event.Skip(); }
		virtual void add( wxCommandEvent& event ) { event.Skip(); }
		virtual void remove( wxCommandEvent& event ) { event.Skip(); }
		virtual void zone00_change( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void zone01_change( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void zone02_change( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void zone03_change( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void change( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxStaticText* m_status;

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("OMEN RGB"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxDIALOG_NO_PARENT );

		~MyFrame1();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PresetDialog
///////////////////////////////////////////////////////////////////////////////
class PresetDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText9;
		wxChoice* m_preset;
		wxButton* m_button_apply;
		wxButton* m_button_set;
		wxButton* m_button_add;
		wxButton* m_button_delete;

		// Virtual event handlers, override them in your derived class
		virtual void close( wxCloseEvent& event ) { event.Skip(); }
		virtual void apply( wxCommandEvent& event ) { event.Skip(); }
		virtual void change( wxCommandEvent& event ) { event.Skip(); }
		virtual void add( wxCommandEvent& event ) { event.Skip(); }
		virtual void remove( wxCommandEvent& event ) { event.Skip(); }


	public:

		PresetDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("OMEN RGB - Presets"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~PresetDialog();

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

