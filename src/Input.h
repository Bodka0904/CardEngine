#pragma once
#include "KeyCodes.h"

namespace Dot
{
    class Input
    {
    public:
        static void Destroy();
        static void TurnOff();
        static void TurnOn();
        static bool KeyPressed(KeyCode key);
        
    private:
        Input();
        ~Input();
        
        bool kbhit();

        static Input *s_Instance;
    };
} 
