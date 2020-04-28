#include "Game.h"


#include <iostream>

Game::Game()
{
    Renderer::Init(0.05f);
    Renderer::SetBackground(BackgroundColor::COLOR_CYAN_B);

     
    m_Player1 = new LocalPlayer("TestDeck.txt");
    m_Player2 = new LocalPlayer("TestDeck.txt");

    m_Animation = new ExplosionAnimation(5.0f);
    m_Animation2 = new ExplosionAnimation(5.0f);
}

Game::~Game()
{
    
}

void Game::Run()
{
    if (Input::KeyPressed(KeyCode::Space))
    {
        Card* card1 = m_Player1->ChooseCard(1);
        Card* card2 = m_Player2->ChooseCard(2);

        card1->ReceiveDamage(card2->GetType(),card2->Attack());
        card2->ReceiveDamage(card1->GetType(),card1->Attack());

        if (!card1->Dead())
            m_Player1->InsertCard(card1);
        else
            m_Player1Dying = true;
        
         
        if (!card2->Dead())
            m_Player2->InsertCard(card2);
        else
            m_Player2Dying = true;     
    }

    
    m_FrameTime.StartFrame();
    if (m_Player1Dying)
    {
        m_Player1Dying = !m_Animation->Update(m_FrameTime.GetSeconds());
        Renderer::SetPixelSequence(Vec2(40,15),"Player one died in this round");
    }

    if (m_Player2Dying)
    {
        m_Player2Dying = !m_Animation2->Update(m_FrameTime.GetSeconds());
        Renderer::SetPixelSequence(Vec2(40,15),"Player two died in this round");
    }

    if (!m_Player1Dying && !m_Player2Dying)
    { 
        m_Player1->ShowCards(Vec2(10,10));   
        m_Player2->ShowCards(Vec2(10,15));
    }
    
    Renderer::Update(m_FrameTime.GetSeconds());
    m_FrameTime.EndFrame();
}