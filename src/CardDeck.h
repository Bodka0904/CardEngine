#pragma once
#include "Card.h"
#include "Math.h"

#include <map>
#include <string>

namespace Dot{

    class CardDeck
    {
    public:
        void LoadDeck(const std::string& filePath);
        
        void Render(const Vec2& pos);
        
    private:
        std::map<Card::Type,Card*> m_Cards;
    };
}