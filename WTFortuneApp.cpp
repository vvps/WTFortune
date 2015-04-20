
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#include "stdafx.h"
#include "WTFortuneApp.h"
#include "WTFortuneMain.h"

IMPLEMENT_APP(WTFortuneApp);

bool WTFortuneApp::OnInit()
{

    WTFortuneDialog* dlg = new WTFortuneDialog(0L);
    dlg->SetIcon(wxICON(WTFish)); // To Set App Icon
    dlg->Show();
    return true;
}
