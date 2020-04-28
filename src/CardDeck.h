#pragma once
#include "Card.h"
#include "Math.h"

#include <unordered_map>
#include <string>
#include <queue>

namespace Dot{

    class CardDeck
    {
    public:
        ~CardDeck();
        void LoadDeck(const std::string& filePath);
        void Render(const Vec2& pos);

        void InsertCard(Card* card);
        Card* GetCard(Card::Type type);
       
    private:
        std::unordered_map<Card::Type,std::queue<Card*>> m_Cards;
    };
}