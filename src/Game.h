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

    void Run(float dt);
    void GetInput();

private:       
    LocalPlayer* m_Player1;
    AIPlayer* m_Player2;
    

    int m_LastRoundDamageToPlOne = 0;
    int m_LastRoundDamageToPlTwo = 0;
    
    Card* m_Player1Card = nullptr;
    Card* m_Player2Card = nullptr;

    bool m_Player1Dying = false;
    bool m_Player2Dying = false;

    bool m_StartRound = false;

    ExplosionAnimation* m_Animation;

    CardMoveAnimation* m_CardMove;
    CardMoveAnimation* m_CardMove2;
};