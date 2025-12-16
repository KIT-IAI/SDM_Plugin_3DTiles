///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "threeDTilesDialog.h"

///////////////////////////////////////////////////////////////////////////

threeDTilesDialog::threeDTilesDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	bSizer1->SetMinSize( wxSize( 400,400 ) );
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	latText = new wxStaticText( this, wxID_ANY, _("Latitude"), wxDefaultPosition, wxDefaultSize, 0 );
	latText->Wrap( -1 );
	fgSizer1->Add( latText, 0, wxALL|wxEXPAND, 5 );

	m_textLat = new wxTextCtrl( this, wxID_ANY, _("LAT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_textLat, 1, wxALL|wxEXPAND, 5 );

	lonText = new wxStaticText( this, wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	lonText->Wrap( -1 );
	fgSizer1->Add( lonText, 1, wxALL|wxEXPAND, 5 );

	m_textLon = new wxTextCtrl( this, wxID_ANY, _("LON"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_textLon, 1, wxALL|wxEXPAND, 5 );


	bSizer1->Add( fgSizer1, 0, wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	m_collapsiblePane1 = new wxCollapsiblePane( this, wxID_ANY, _("settings"), wxDefaultPosition, wxDefaultSize, wxCP_DEFAULT_STYLE );
	m_collapsiblePane1->Collapse( false );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText3 = new wxStaticText( m_collapsiblePane1->GetPane(), wxID_ANY, _("Radius"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer2->Add( m_staticText3, 0, wxALL, 5 );

	m_textRad = new wxTextCtrl( m_collapsiblePane1->GetPane(), wxID_ANY, _("RADIUS"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_textRad, 0, wxALL|wxEXPAND, 5 );

	m_staticText41 = new wxStaticText( m_collapsiblePane1->GetPane(), wxID_ANY, _("Download directory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	fgSizer2->Add( m_staticText41, 0, wxALL, 5 );

	m_dirPicker1 = new wxDirPickerCtrl( m_collapsiblePane1->GetPane(), wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	fgSizer2->Add( m_dirPicker1, 0, wxALL|wxEXPAND, 5 );

	clipText = new wxStaticText( m_collapsiblePane1->GetPane(), wxID_ANY, _("Clip to Model Bounding-Box:"), wxDefaultPosition, wxDefaultSize, 0 );
	clipText->Wrap( -1 );
	fgSizer2->Add( clipText, 0, wxALL, 5 );

	m_checkBox1 = new wxCheckBox( m_collapsiblePane1->GetPane(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1->SetValue(true);
	fgSizer2->Add( m_checkBox1, 0, wxALL, 5 );


	m_collapsiblePane1->GetPane()->SetSizer( fgSizer2 );
	m_collapsiblePane1->GetPane()->Layout();
	fgSizer2->Fit( m_collapsiblePane1->GetPane() );
	bSizer1->Add( m_collapsiblePane1, 0, wxEXPAND | wxALL, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();

	bSizer1->Add( m_sdbSizer1, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( threeDTilesDialog::m_buttonDownloadOnButtonClick ), NULL, this );
}

threeDTilesDialog::~threeDTilesDialog()
{
}
