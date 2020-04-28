#pragma once
#include "Input.h"
#include "Renderer.h"
#include "Math.h"
#include "CardDeck.h"
#include "Card.h"

using namespace Dot;

struct Player
{
    Player(const Vec2& Pos,const Vec2& Size)
        : position(Pos),size(Size)
    {}

    void Draw()
    {
        Renderer::DrawQuad(position,position+size,'0');
    }
    Vec2 position;
    Vec2 size;
};

class Game
{
public:
    Game();
    ~Game();

    void Run(float dt);

private:
    Player player;
    CardDeck deck;
        
};