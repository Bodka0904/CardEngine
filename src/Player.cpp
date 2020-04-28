#include "Player.h"
#include "Input.h"

#include <iostream>

namespace Dot {

    Player::Player(const std::string& deckPath)     
    {
        m_Deck.LoadDeck(deckPath);
    }

    Player::~Player()
    {

    }

    void Player::ShowCards(const Vec2& pos)
    {
        m_Deck.Render(pos);
    }

    void Player::InsertCard(Card* card)
    {
        m_Deck.InsertCard(card);
    }

    LocalPlayer::LocalPlayer(const std::string& deckPath)
        : Player(deckPath)
    {}

    void LocalPlayer::Update()
    {
        
    }

    Card* LocalPlayer::ChooseCard(int x)
    {
        std::string cardType;
        Input::TurnOff();
        std::cout << x << std::endl;
        getline(std::cin,cardType);
        Input::TurnOn();

        Card * card = nullptr;
        if (cardType == "Warrior")
        {
            card = m_Deck.GetCard(Card::Warrior);
        }
        else if(cardType == "Mage")
        {
            card = m_Deck.GetCard(Card::Mage);
        }
        else if (cardType == "Archer")
        {
            card = m_Deck.GetCard(Card::Archer);
        }
        else if (cardType == "Rogue")
        {
            card = m_Deck.GetCard(Card::Rogue);
        }
        if (card == nullptr)
        {
            std::cout << "No card of specified type choose another card" << std::endl;
            return ChooseCard(x);
        }
        return card;
    }
} 