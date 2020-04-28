#pragma once
#include "CardDeck.h"
#include "Math.h"

#include <string>

namespace Dot {
    class Player
    {
    public:
        Player(const std::string& deckPath);
        virtual ~Player();

        void ShowCards(const Vec2& pos);
        void InsertCard(Card* card);
        virtual void Update() = 0;
    
        
        virtual Card* ChooseCard(int x) = 0;
    protected:
        CardDeck m_Deck;
    };


    class LocalPlayer : public Player
    {
    public:
        LocalPlayer(const std::string& deckPath);
        virtual void Update();

        virtual Card* ChooseCard(int x) override;
    };
}