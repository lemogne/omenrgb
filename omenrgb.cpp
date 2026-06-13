///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "omenrgb.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText10 = new wxStaticText( m_panel1, wxID_ANY, wxT("Palette"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer9->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxArrayString m_palettesChoices;
	m_palettes = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_palettesChoices, 0 );
	m_palettes->SetSelection( 0 );
	bSizer9->Add( m_palettes, 1, wxALL, 5 );


	bSizer7->Add( bSizer9, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_button_new = new wxButton( m_panel1, wxID_ANY, wxT("New..."), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_new->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_PLUS), wxASCII_STR(wxART_BUTTON) ) );
	bSizer14->Add( m_button_new, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button_delete = new wxButton( m_panel1, wxID_ANY, wxT("Delete..."), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_delete->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_DELETE), wxASCII_STR(wxART_BUTTON) ) );
	bSizer14->Add( m_button_delete, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer7->Add( bSizer14, 0, wxEXPAND, 5 );

	palette_sizer = new wxGridSizer( 0, 2, 0, 0 );


	bSizer7->Add( palette_sizer, 0, wxEXPAND, 5 );

	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_button_set = new wxButton( m_panel1, wxID_ANY, wxT("Save..."), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_set->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_TICK_MARK), wxASCII_STR(wxART_BUTTON) ) );
	m_button_set->SetBitmapDisabled( wxNullBitmap );
	bSizer13->Add( m_button_set, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button_add = new wxButton( m_panel1, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_add->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_ADD_BOOKMARK), wxASCII_STR(wxART_BUTTON) ) );
	bSizer13->Add( m_button_add, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer7->Add( bSizer13, 0, wxEXPAND, 5 );


	m_panel1->SetSizer( bSizer7 );
	m_panel1->Layout();
	bSizer7->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, wxT("Palette"), true );
	m_panel2 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText11 = new wxStaticText( m_panel2, wxID_ANY, wxT("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer2->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	m_slider1 = new wxSlider( m_panel2, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	fgSizer2->Add( m_slider1, 0, wxALL|wxEXPAND, 5 );

	m_staticText12 = new wxStaticText( m_panel2, wxID_ANY, wxT("Brightness"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	fgSizer2->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider2 = new wxSlider( m_panel2, wxID_ANY, 100, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	fgSizer2->Add( m_slider2, 0, wxALL|wxEXPAND, 5 );

	m_staticText9 = new wxStaticText( m_panel2, wxID_ANY, wxT("Animation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer2->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	wxArrayString m_animationsChoices;
	m_animations = new wxChoice( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_animationsChoices, 0 );
	m_animations->SetSelection( 0 );
	fgSizer2->Add( m_animations, 0, wxALL, 5 );


	bSizer10->Add( fgSizer2, 0, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer211;
	fgSizer211 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer211->SetFlexibleDirection( wxBOTH );
	fgSizer211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_button_add1 = new wxButton( m_panel2, wxID_ANY, wxT("New..."), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_add1->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_PLUS), wxASCII_STR(wxART_BUTTON) ) );
	fgSizer211->Add( m_button_add1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button_delete1 = new wxButton( m_panel2, wxID_ANY, wxT("Delete..."), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_delete1->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_DELETE), wxASCII_STR(wxART_BUTTON) ) );
	fgSizer211->Add( m_button_delete1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer10->Add( fgSizer211, 1, wxEXPAND, 5 );


	m_panel2->SetSizer( bSizer10 );
	m_panel2->Layout();
	bSizer10->Fit( m_panel2 );
	m_notebook1->AddPage( m_panel2, wxT("Animation"), false );

	bSizer1->Add( m_notebook1, 1, wxALL|wxEXPAND, 5 );

	m_status = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_status->Wrap( -1 );
	bSizer1->Add( m_status, 0, wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_palettes->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::apply ), NULL, this );
	m_button_new->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::add ), NULL, this );
	m_button_delete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::remove ), NULL, this );
	m_button_set->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::save_config ), NULL, this );
	m_button_add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::add_palette_color_event ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Connect( wxEVT_SLIDER, wxCommandEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Connect( wxEVT_SLIDER, wxCommandEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_animations->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::animation_change ), NULL, this );
	m_button_add1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::add ), NULL, this );
	m_button_delete1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::remove ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_palettes->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::apply ), NULL, this );
	m_button_new->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::add ), NULL, this );
	m_button_delete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::remove ), NULL, this );
	m_button_set->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::save_config ), NULL, this );
	m_button_add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::add_palette_color_event ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider1->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MyFrame1::set_speed ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_slider2->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MyFrame1::set_brightness ), NULL, this );
	m_animations->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::animation_change ), NULL, this );
	m_button_add1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::add ), NULL, this );
	m_button_delete1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::remove ), NULL, this );

}

TextEntryDialog::TextEntryDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer7->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_name = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_name->SetMinSize( wxSize( 200,-1 ) );

	bSizer7->Add( m_name, 1, wxALL, 5 );


	bSizer6->Add( bSizer7, 1, wxEXPAND, 5 );

	m_sdbSizer2 = new wxStdDialogButtonSizer();
	m_sdbSizer2OK = new wxButton( this, wxID_OK );
	m_sdbSizer2->AddButton( m_sdbSizer2OK );
	m_sdbSizer2Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer2->AddButton( m_sdbSizer2Cancel );
	m_sdbSizer2->Realize();

	bSizer6->Add( m_sdbSizer2, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();
	bSizer6->Fit( this );

	this->Centre( wxBOTH );
}

TextEntryDialog::~TextEntryDialog()
{
}
