#pragma once
#include "Card.h"
#include "Math.h"

#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>

namespace Dot{

    class CardDeck
    {
    public:
        ~CardDeck();
        void LoadDeck(const std::string& filePath);
        void Render(const Vec2& pos);

        void InsertCard(Card* card);
        Card* GetCard(Card::Type type);

        template <typename T>
        T* GetCopyCard(Card::Type type)
        {
            if (!m_Cards[type].empty())
            {
                T* card = new T(*(T*)m_Cards[type].front());
                return card;
            }
            return nullptr;
        }

        bool IsEmpty();
       
    private:
        std::unordered_map<Card::Type,std::queue<Card*>> m_Cards;
    };
}