#ifndef WTFORTUNEAPP_H
#define WTFORTUNEAPP_H

#include "stdafx.h"
#include <wx/app.h>

class WTFortuneApp : public wxApp
{
    public:
        wxIcon* WTFish;
        virtual bool OnInit();
};

#endif // WTFORTUNEAPP_H
