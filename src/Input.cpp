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
    int Input::KeyPressed()
    {
        static bool initflag = false;
        static const int STDIN = 0;

        //if (!initflag) 
        {
            // Use termios to turn off line buffering
            struct termios term;
            tcgetattr(STDIN, &term);
            term.c_lflag &= ~ICANON;
            tcsetattr(STDIN, TCSANOW, &term);
            setbuf(stdin, NULL);
            initflag = true;
        }

        int nbbytes;
        ioctl(STDIN, FIONREAD, &nbbytes);  // 0 is STDIN
        return nbbytes;
    }   

}

