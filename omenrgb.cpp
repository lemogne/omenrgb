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

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Set Keyboard Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer1->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 4, 2, 0, 0 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Zone 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	gSizer1->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	m_colourPicker1 = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	gSizer1->Add( m_colourPicker1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Zone 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	gSizer1->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	m_colourPicker2 = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	gSizer1->Add( m_colourPicker2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Zone 3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	gSizer1->Add( m_staticText21, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	m_colourPicker3 = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	gSizer1->Add( m_colourPicker3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Zone 4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	gSizer1->Add( m_staticText31, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	m_colourPicker4 = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	gSizer1->Add( m_colourPicker4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1->Add( gSizer1, 1, wxEXPAND, 5 );

	m_button_presets = new wxButton( this, wxID_ANY, wxT("Presets..."), wxDefaultPosition, wxSize( -1,-1 ), 0 );

	m_button_presets->SetBitmap( wxNullBitmap );
	bSizer1->Add( m_button_presets, 0, wxALL|wxEXPAND, 5 );

	m_status = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_status->Wrap( -1 );
	bSizer1->Add( m_status, 0, wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_colourPicker1->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone00_change ), NULL, this );
	m_colourPicker2->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone01_change ), NULL, this );
	m_colourPicker3->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone02_change ), NULL, this );
	m_colourPicker4->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone03_change ), NULL, this );
	m_button_presets->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::open_presets ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_colourPicker1->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone00_change ), NULL, this );
	m_colourPicker2->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone01_change ), NULL, this );
	m_colourPicker3->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone02_change ), NULL, this );
	m_colourPicker4->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone03_change ), NULL, this );
	m_button_presets->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::open_presets ), NULL, this );

}

PresetDialog::PresetDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer3->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxArrayString m_presetChoices;
	m_preset = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_presetChoices, 0 );
	m_preset->SetSelection( 0 );
	m_preset->SetMinSize( wxSize( 200,-1 ) );

	bSizer3->Add( m_preset, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_button_apply = new wxButton( this, wxID_ANY, wxT("Apply"), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_apply->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_TICK_MARK), wxASCII_STR(wxART_BUTTON) ) );
	m_button_apply->SetBitmapDisabled( wxNullBitmap );
	fgSizer2->Add( m_button_apply, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button_set = new wxButton( this, wxID_ANY, wxT("Change"), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_set->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_EDIT), wxASCII_STR(wxART_BUTTON) ) );
	fgSizer2->Add( m_button_set, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button_add = new wxButton( this, wxID_ANY, wxT("Add..."), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_add->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_PLUS), wxASCII_STR(wxART_BUTTON) ) );
	fgSizer2->Add( m_button_add, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button_delete = new wxButton( this, wxID_ANY, wxT("Delete..."), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_delete->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_DELETE), wxASCII_STR(wxART_BUTTON) ) );
	fgSizer2->Add( m_button_delete, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer2->Add( fgSizer2, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( PresetDialog::close ) );
	m_button_apply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresetDialog::apply ), NULL, this );
	m_button_set->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresetDialog::change ), NULL, this );
	m_button_add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresetDialog::add ), NULL, this );
	m_button_delete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresetDialog::remove ), NULL, this );
}

PresetDialog::~PresetDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( PresetDialog::close ) );
	m_button_apply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresetDialog::apply ), NULL, this );
	m_button_set->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresetDialog::change ), NULL, this );
	m_button_add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresetDialog::add ), NULL, this );
	m_button_delete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PresetDialog::remove ), NULL, this );

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
