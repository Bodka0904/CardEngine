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
        bool IsEmpty() {return m_Deck.IsEmpty();}
        virtual void Update() = 0;

        
        virtual Card* ChooseCard(int x) = 0;
    protected:
        CardDeck m_Deck;
    };


    class LocalPlayer : public Player
    {
    public:
        LocalPlayer(const std::string& deckPath);
        virtual void Update() override;

        virtual Card* ChooseCard(int x) override;
    };


    class AIPlayer : public Player
    {
    public:
        AIPlayer(const std::string& deck,unsigned int difficulty);

        virtual void Update() override;

        virtual Card* ChooseCard(int x) override;

        void HandleEnemyType(Card* card);
    private:
        bool Check(Card *cardPlayer,Card::Type type);
        Card* ChooseFirstCard(Card::Type type);
    private:
        Card* m_ChoosenCard;
        unsigned int m_Difficulty;
    };
}