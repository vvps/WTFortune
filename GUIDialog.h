
#ifndef __GUIDIALOG_H__
#define __GUIDIALOG_H__


#include "stdafx.h"

class GUIDialog : public wxDialog
{
	private:

	protected:

		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnFortune( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSettings( wxCommandEvent& event ) { event.Skip(); }

		wxIcon WTFishIcon;
		wxTextCtrl* fortuneText;
		//wxBitmapButton* BtnFortuneBMP;
		wxButton* BtnFortune;
		wxButton* BtnSettings;
		wxTextFile* fortuneSettingsFile;


	public:

		GUIDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("WTFortune"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~GUIDialog();

};

#endif //__GUIDIALOG_H__
