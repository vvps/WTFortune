
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "stdafx.h"
#include "GUIDialog.h"

///////////////////////////////////////////////////////////////////////////

GUIDialog::GUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	//WTFishIcon.LoadFile("WTFish.ico");
	//this->SetIcon(WTFishIcon);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

    fortuneText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(500,250), wxNO_BORDER | wxTE_MULTILINE | wxTE_READONLY );

	bSizer1->Add( fortuneText, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

    //wxImage::AddHandler( new wxPNGHandler );
    //BtnFortuneBMP = new wxBitmapButton( this, wxID_ANY, wxBitmap(wxT("WTFish.png"), wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(70,70), 0);
	//bSizer2->Add( BtnFortuneBMP, 0, wxALL, 5 );

	BtnFortune = new wxButton( this, wxID_ANY, wxT("&Fortune"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( BtnFortune, 0, wxALL, 5 );

	BtnSettings = new wxButton( this, wxID_ANY, wxT("&Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( BtnSettings, 0, wxALL, 5 );

	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	BtnFortune->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnFortune ), NULL, this );
	BtnSettings->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnSettings ), NULL, this );
}

GUIDialog::~GUIDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	BtnFortune->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnFortune ), NULL, this );
	BtnSettings->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnSettings ), NULL, this );

}
