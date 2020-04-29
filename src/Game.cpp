#include "Game.h"


#include <iostream>
#include <sstream>


Game::Game()
{
    Renderer::Init(0.05f);
    Renderer::SetBackground(BackgroundColor::COLOR_CYAN_B);

     
    m_Player1 = new LocalPlayer("TestDeck.txt");
    m_Player2 = new AIPlayer("TestDeck.txt",5);

    m_Animation = new ExplosionAnimation(5.0f);

    m_CardMove = new CardMoveAnimation(15.0f,Vec2(0,-1),Vec2(5,5));
    m_CardMove2 = new CardMoveAnimation(15.0f,Vec2(0,1),Vec2(5,5));
}

Game::~Game()
{
    
}

void Game::Run(float dt)
{
    // Start round play animation and and let cards fight //
    if (m_StartRound)
    {
        m_StartRound = !m_CardMove->Update(Vec2(45,35),dt*10) ;
        m_CardMove2->Update(Vec2(45,5),dt*10);

        if (!m_StartRound)
        {
            m_LastRoundDamageToPlOne = m_Player1Card->ReceiveDamage(m_Player2Card->GetType(),m_Player2Card->Attack());
            m_LastRoundDamageToPlTwo = m_Player2Card->ReceiveDamage(m_Player1Card->GetType(),m_Player1Card->Attack());

            if (!m_Player1Card->Dead())
                m_Player1->InsertCard(m_Player1Card);
            else
                m_Player1Dying = true;
        
         
            if (!m_Player2Card->Dead())
                m_Player2->InsertCard(m_Player2Card);
            else
                m_Player2Dying = true;     
        }
    }
    /////////////////////////////////////////////////////////

    // Round is over show who died this round //
    if (m_Player1Dying && m_Player2Dying)
    {
        m_Player1Dying = !m_Animation->Update(Vec2(50,19),dt*2);
        m_Player2Dying = m_Player1Dying;
        Renderer::SetPixelSequence(Vec2(35,19),"Both players died in this round");
    }
    else if (m_Player1Dying)
    {
        m_Player1Dying = !m_Animation->Update(Vec2(50,19),dt*2);
        Renderer::SetPixelSequence(Vec2(35,19),"Player 1 died in this round");
    }
    else if (m_Player2Dying)
    {
        m_Player2Dying = !m_Animation->Update(Vec2(50,19),dt*2);
        Renderer::SetPixelSequence(Vec2(35,19),"Player 2 died in this round");
    }
    /////////////////////////////////////////

    // Show cards or if one of the player does not have card show winner //
    if (!m_Player1Dying && !m_Player2Dying && !m_StartRound)
    { 
        if (m_Player1->IsEmpty() && m_Player2->IsEmpty())
            Renderer::SetPixelSequence(Vec2(38,19),"Split");
        else if (m_Player1->IsEmpty())
            Renderer::SetPixelSequence(Vec2(38,19),"Player 2 won the match");
        else if (m_Player2->IsEmpty())
            Renderer::SetPixelSequence(Vec2(38,19),"Player 1 won the match");
        else
        {
            m_Player1->ShowCards(Vec2(35,5));   
            m_Player2->ShowCards(Vec2(35,35));

            std::stringstream ss;
            ss << "Player 1 received damage ";
            ss << m_LastRoundDamageToPlOne;
            Renderer::SetPixelSequence(Vec2(35,7),ss.str());
            std::stringstream ss2;
            ss2 << "Player 2 received damage ";
            ss2 << m_LastRoundDamageToPlTwo;
            Renderer::SetPixelSequence(Vec2(35,32),ss2.str());
        }     
    }
    //////////////////////////////////////////////
    
    Renderer::Update(dt);
}

void Game::GetInput()
{
    if (!m_Player1Dying && !m_Player2Dying && !m_StartRound)
    {
        if (Input::KeyPressed(KeyCode::Space))
        {
            m_Player1Card = m_Player1->ChooseCard(1);

            m_Player2->HandleEnemyType(m_Player1Card);
            m_Player2Card = m_Player2->ChooseCard(2);

            m_StartRound = true;
        }
    }
}