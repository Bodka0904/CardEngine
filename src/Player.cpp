#include "Player.h"
#include "Input.h"

#include <iostream>
#include <random>

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

    AIPlayer::AIPlayer(const std::string& deck,unsigned int difficulty)
        : 
        Player(deck),
        m_ChoosenCard(nullptr),
        m_Difficulty(difficulty)
    {
    }

    void AIPlayer::Update()
    {

    }

    Card* AIPlayer::ChooseCard(int x)
    {
        return m_ChoosenCard;
    }


    void AIPlayer::HandleEnemyType(Card * card)
    {
        std::mt19937 rng;
        std::uniform_int_distribution<int> dist(0,m_Difficulty);
        if (Check(card,Card::Warrior) && dist(rng))
        {
            m_ChoosenCard = m_Deck.GetCard(Card::Warrior);
            if (!m_ChoosenCard)
                m_ChoosenCard = ChooseFirstCard(Card::Warrior);
        }
        else if (Check(card,Card::Archer) && !dist(rng))
        {
            m_ChoosenCard = m_Deck.GetCard(Card::Archer);
            if (!m_ChoosenCard)
                m_ChoosenCard = ChooseFirstCard(Card::Warrior);
        }
        else if (Check(card,Card::Rogue) && !dist(rng))
        {
            m_ChoosenCard = m_Deck.GetCard(Card::Rogue);
            if (!m_ChoosenCard)
                m_ChoosenCard = ChooseFirstCard(Card::Warrior);
        }
        else if (Check(card,Card::Mage) && !dist(rng))
        {
            m_ChoosenCard = m_Deck.GetCard(Card::Mage);
            if (!m_ChoosenCard)
                m_ChoosenCard = ChooseFirstCard(Card::Warrior);
        }
        else
        {     
            m_ChoosenCard = ChooseFirstCard(Card::Warrior);
        }
       
    }
    Card* AIPlayer::ChooseFirstCard(Card::Type type)
    {
        Card * card = m_Deck.GetCard(type);
        if (!card)
        {   
            int next = type + 1;
            return ChooseFirstCard((Card::Type)next);
        }
        return card;
    }

    bool AIPlayer::Check(Card* cardPlayer,Card::Type type)
    {
        Card * card = nullptr;
        if (type == Card::Warrior)
            card = m_Deck.GetCopyCard<WarriorCard>(type);
        else if (type == Card::Archer)    
            card = m_Deck.GetCopyCard<ArcherCard>(type);
        else if (type == Card::Rogue)  
            card = m_Deck.GetCopyCard<RogueCard>(type);
        else if (type == Card::Mage) 
            card = m_Deck.GetCopyCard<MageCard>(type);
        
        if (!card)
            return false;


        Card* playerCopy = nullptr;
        if (cardPlayer->GetType() == Card::Warrior)
            playerCopy = new WarriorCard(*(WarriorCard*)cardPlayer);
        else if (cardPlayer->GetType() == Card::Archer)
            playerCopy = new ArcherCard(*(ArcherCard*)cardPlayer);
        else if (cardPlayer->GetType() == Card::Rogue)
            playerCopy = new RogueCard(*(RogueCard*)cardPlayer);
        else if (cardPlayer->GetType() == Card::Mage)
            playerCopy = new MageCard(*(MageCard*)cardPlayer);

        if (!playerCopy)
            return false;
       
        card->ReceiveDamage(playerCopy->GetType(),playerCopy->Attack());
        playerCopy->ReceiveDamage(card->GetType(),card->Attack());
        
        if (playerCopy->Dead() || !card->Dead())
        {
            delete card;
            delete playerCopy;
            return true;
        }
                   
        delete card;
        delete playerCopy;
        return false;
    }

} 