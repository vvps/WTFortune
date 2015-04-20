/***************************************************************
 * Name:      WTFortuneMain.h
 * Purpose:   Defines Application Frame
 * Author:    Vijay Parsi
 * Created:   2011-12-01
 * Copyright: Vijay Parsi
 * License:
 **************************************************************/

#ifndef WTFORTUNEMAIN_H
#define WTFORTUNEMAIN_H

#include "stdafx.h"
#include "WTFortuneApp.h"
#include "GUIDialog.h"

class WTFortuneDialog: public GUIDialog
{
    public:
        WTFortuneDialog(wxDialog *dlg);
        ~WTFortuneDialog();
    private:
        const char *fortuneprefs;
        wxString fortuneSource;

        virtual void OnClose(wxCloseEvent& event);
        virtual void OnSettings(wxCommandEvent& event);
        virtual void OnFortune(wxCommandEvent& event);
};
#endif // WTFORTUNEMAIN_H
