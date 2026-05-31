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

	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText10 = new wxStaticText( m_panel1, wxID_ANY, wxT("Palette"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer9->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxArrayString m_choice3Choices;
	m_choice3 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice3Choices, 0 );
	m_choice3->SetSelection( 0 );
	bSizer9->Add( m_choice3, 1, wxALL, 5 );


	bSizer7->Add( bSizer9, 0, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_button_add = new wxButton( m_panel1, wxID_ANY, wxT("New..."), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_add->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_PLUS), wxASCII_STR(wxART_BUTTON) ) );
	fgSizer21->Add( m_button_add, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button_delete = new wxButton( m_panel1, wxID_ANY, wxT("Delete..."), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_delete->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_DELETE), wxASCII_STR(wxART_BUTTON) ) );
	fgSizer21->Add( m_button_delete, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer7->Add( fgSizer21, 0, wxEXPAND, 5 );

	m_collapsiblePane1 = new wxCollapsiblePane( m_panel1, wxID_ANY, wxT("Colours"), wxDefaultPosition, wxDefaultSize, wxCP_DEFAULT_STYLE );
	m_collapsiblePane1->Collapse( true );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText2 = new wxStaticText( m_collapsiblePane1->GetPane(), wxID_ANY, wxT("Zone 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer4->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	m_colourPicker1 = new wxColourPickerCtrl( m_collapsiblePane1->GetPane(), wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer4->Add( m_colourPicker1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText3 = new wxStaticText( m_collapsiblePane1->GetPane(), wxID_ANY, wxT("Zone 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer4->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	m_colourPicker2 = new wxColourPickerCtrl( m_collapsiblePane1->GetPane(), wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer4->Add( m_colourPicker2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText21 = new wxStaticText( m_collapsiblePane1->GetPane(), wxID_ANY, wxT("Zone 3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer4->Add( m_staticText21, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	m_colourPicker3 = new wxColourPickerCtrl( m_collapsiblePane1->GetPane(), wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer4->Add( m_colourPicker3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText31 = new wxStaticText( m_collapsiblePane1->GetPane(), wxID_ANY, wxT("Zone 4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer4->Add( m_staticText31, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	m_colourPicker4 = new wxColourPickerCtrl( m_collapsiblePane1->GetPane(), wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer4->Add( m_colourPicker4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button_set = new wxButton( m_collapsiblePane1->GetPane(), wxID_ANY, wxT("Apply"), wxDefaultPosition, wxDefaultSize, 0 );

	m_button_set->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_TICK_MARK), wxASCII_STR(wxART_BUTTON) ) );
	m_button_set->SetBitmapDisabled( wxNullBitmap );
	fgSizer4->Add( m_button_set, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxHORIZONTAL );

	m_button10 = new wxButton( m_collapsiblePane1->GetPane(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );

	m_button10->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_ADD_BOOKMARK), wxASCII_STR(wxART_BUTTON) ) );
	m_button10->SetMaxSize( wxSize( 37,-1 ) );

	bSizer91->Add( m_button10, 0, wxALL, 5 );

	m_button101 = new wxButton( m_collapsiblePane1->GetPane(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );

	m_button101->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_DEL_BOOKMARK), wxASCII_STR(wxART_BUTTON) ) );
	m_button101->SetMaxSize( wxSize( 37,-1 ) );

	bSizer91->Add( m_button101, 0, wxALL, 5 );


	fgSizer4->Add( bSizer91, 1, wxEXPAND, 5 );


	m_collapsiblePane1->GetPane()->SetSizer( fgSizer4 );
	m_collapsiblePane1->GetPane()->Layout();
	fgSizer4->Fit( m_collapsiblePane1->GetPane() );
	bSizer7->Add( m_collapsiblePane1, 1, wxEXPAND | wxALL, 5 );


	m_panel1->SetSizer( bSizer7 );
	m_panel1->Layout();
	bSizer7->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, wxT("Palette"), false );
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

	m_staticText9 = new wxStaticText( m_panel2, wxID_ANY, wxT("Animation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer2->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	wxArrayString m_choice2Choices;
	m_choice2 = new wxChoice( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice2Choices, 0 );
	m_choice2->SetSelection( 0 );
	fgSizer2->Add( m_choice2, 0, wxALL, 5 );


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

	bSizer1->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );

	m_status = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_status->Wrap( -1 );
	bSizer1->Add( m_status, 0, wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button_add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::add ), NULL, this );
	m_button_delete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::remove ), NULL, this );
	m_colourPicker1->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone00_change ), NULL, this );
	m_colourPicker2->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone01_change ), NULL, this );
	m_colourPicker3->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone02_change ), NULL, this );
	m_colourPicker4->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone03_change ), NULL, this );
	m_button_set->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::apply ), NULL, this );
	m_button_add1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::add ), NULL, this );
	m_button_delete1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::remove ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_button_add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::add ), NULL, this );
	m_button_delete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::remove ), NULL, this );
	m_colourPicker1->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone00_change ), NULL, this );
	m_colourPicker2->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone01_change ), NULL, this );
	m_colourPicker3->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone02_change ), NULL, this );
	m_colourPicker4->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::zone03_change ), NULL, this );
	m_button_set->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::apply ), NULL, this );
	m_button_add1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::add ), NULL, this );
	m_button_delete1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::remove ), NULL, this );

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
