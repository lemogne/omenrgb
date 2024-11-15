///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
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
#include <wx/clrpicker.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxColourPickerCtrl* m_colourPicker1;
		wxStaticText* m_staticText3;
		wxColourPickerCtrl* m_colourPicker2;
		wxStaticText* m_staticText21;
		wxColourPickerCtrl* m_colourPicker3;
		wxStaticText* m_staticText31;
		wxColourPickerCtrl* m_colourPicker4;

		// Virtual event handlers, override them in your derived class
		virtual void zone00_change( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void zone01_change( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void zone02_change( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void zone03_change( wxColourPickerEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxDIALOG_NO_PARENT );

		~MyFrame1();

};

