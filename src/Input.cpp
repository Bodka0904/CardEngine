#include "Input.h"

#include <iostream>   // Standard Header
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stropts.h>
#include <stdio.h>


namespace Dot
{
    Input *Input::s_Instance = new Input();
    Input::Input()
    {
        TurnOn();
    }

    Input::~Input()
    {
        TurnOff();
    }
    void Input::Destroy()
    {
        delete s_Instance;
    }
    void Input::TurnOff()
    {
        termios term;
        tcgetattr(0, &term);
        term.c_lflag |= ICANON | ECHO;
        tcsetattr(0, TCSANOW, &term);
    }
    void Input::TurnOn()
    {
        termios term;
        tcgetattr(0, &term);
        term.c_lflag &= ~(ICANON | ECHO); // Disable echo as well
        tcsetattr(0, TCSANOW, &term);
    }
    bool Input::KeyPressed(KeyCode key)
    {
        int input = 0;
        if (s_Instance->kbhit())
        {
            input = getchar();
            tcflush(0, TCIFLUSH);   
        }
        return input == static_cast<std::underlying_type_t<KeyCode>>(key);
    }   

    bool Input::kbhit()
    {
        int byteswaiting;
        ioctl(0, FIONREAD, &byteswaiting);

        return byteswaiting > 0;
    }
}

