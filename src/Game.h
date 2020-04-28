#pragma once
#include "Input.h"
#include "Renderer.h"
#include "Math.h"
#include "CardDeck.h"
#include "Card.h"
#include "Player.h"
#include "Animation.h"
#include "FrameTime.h"

using namespace Dot;

class Game
{
public:
    Game();
    ~Game();

    void Run();

private:       
    FrameTime m_FrameTime;
    LocalPlayer* m_Player1;
    LocalPlayer* m_Player2;


    bool m_Player1Dying = false;
    bool m_Player2Dying = false;

    ExplosionAnimation* m_Animation;
    ExplosionAnimation* m_Animation2;
};