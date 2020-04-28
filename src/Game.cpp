#include "Game.h"


Game::Game()
    :
    player(Vec2(10,10),Vec2(5,5))
{
    Renderer::Init(0.05f);
    Renderer::SetBackground(BackgroundColor::COLOR_CYAN_B);

    deck.LoadDeck("TestDeck.txt");
}

Game::~Game()
{
    
}

void Game::Run(float dt)
{
    if (Input::KeyPressed(KeyCode::a))
        player.position.x -= 2;
    else if (Input::KeyPressed(KeyCode::d))
        player.position.x += 2;
    else if (Input::KeyPressed(KeyCode::w))
        player.position.y -= 2;
    else if (Input::KeyPressed(KeyCode::s))
        player.position.y += 2;

    player.Draw();
    deck.Render(Vec2(10,10));
    Renderer::Update(dt);
}