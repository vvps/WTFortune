
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#include "stdafx.h"
#include "WTFortuneMain.h"

WTFortuneDialog::WTFortuneDialog(wxDialog *dlg): GUIDialog(dlg)
{
     wxTextFile fortuneSettingsFile("WTFortuneSettings.ini");
     if (fortuneSettingsFile.Exists())
     {
        fortuneSettingsFile.Open();
        fortuneSource = fortuneSettingsFile.GetFirstLine();
        fortuneSettingsFile.Close();
     }
}

WTFortuneDialog::~WTFortuneDialog()
{
	//destructor
}

void WTFortuneDialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void WTFortuneDialog::OnSettings(wxCommandEvent &event)
{
     wxDirDialog dlg(NULL, "Choose fortune source directory", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
     if (dlg.ShowModal() == wxID_OK)
        {
            fortuneSource = dlg.GetPath();

            wxTextFile fortuneSettingsFile("WTFortuneSettings.ini");
            if (fortuneSettingsFile.Exists() == FALSE)
            {
                fortuneSettingsFile.Create("WTFortuneSettings.ini");
            }

            fortuneSettingsFile.Open();
            fortuneSettingsFile.AddLine(fortuneSource);
            fortuneSettingsFile.Write();
            fortuneSettingsFile.Close();
        }
}

void WTFortuneDialog::OnFortune(wxCommandEvent &event)
{

    fortuneText->Clear();
    wxArrayString *fortuneFiles = new wxArrayString();
    int numOfFiles, fileNumber;
    wxString fortuneFileName;
    wxString fortune;

    wxDir fortuneDir(fortuneSource);

    if (fortuneDir.IsOpened())
    {
        fortuneDir.GetAllFiles(fortuneSource, fortuneFiles, wxEmptyString, wxDIR_DEFAULT);
        numOfFiles = fortuneFiles->GetCount(); //number of fortune files

        srand ( time(NULL) ); // initialise random seed
        fileNumber = rand() % numOfFiles; // determine file number from random
        fortuneFileName = fortuneFiles->Item(fileNumber); // get the filename from the file array

        //open the file and check for the number of cookies
        wxTextFile fortuneFile(fortuneFileName);
        if (fortuneFile.Exists())
        {
            fortune = "";
            fortuneFile.Open();

            int numOfLines = fortuneFile.GetLineCount();
            int scanCookies = 0, numOfCookies = 0;
            wxString searchPer;

            for (int i = 1; i < numOfLines; ++i)
            {
                searchPer = fortuneFile.GetLine(i);
                if (searchPer == "%")
                    ++numOfCookies;
            }
            fortuneFile.Close();

            srand ( time(NULL) ); // initialise random seed
            int cookieNumber = rand() % numOfCookies; // determine file number from random

            fortuneFile.Open();
            for (int i = 1; i < numOfLines; ++i)
            {
                searchPer = fortuneFile.GetLine(i);
                if (searchPer == "%")
                    ++scanCookies;

                if ((scanCookies == cookieNumber) && (searchPer != "%"))
                {
                    fortune += fortuneFile.GetLine(i);
                    fortune += "\n";
                }

            }


            fortuneFile.Close();
        }
        else
        {
            fortune = "error: no cookies for you!";
        }

        fortuneText->AppendText(fortune);
    }

}
