#include "Renderer.h"
#include "Input.h"
#include "FrameTime.h"
#include "Game.h"

#include <iostream>


#include "CardDeck.h"


    using namespace Dot;

    int main()
    {
        FrameTime frameTime;
        bool running = true;
        Game game;
        while (running)
        {
            frameTime.StartFrame();
            game.Run(frameTime.GetSeconds());
            frameTime.EndFrame();

            game.GetInput();
            if (Input::KeyPressed(KeyCode::q))
                running = false;
        }    

        Renderer::Shutdown();
        Input::Destroy();

        return 0;
    }
