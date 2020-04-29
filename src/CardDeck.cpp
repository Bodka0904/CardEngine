#include "CardDeck.h"
#include "Renderer.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>

namespace Dot{

    struct CardFormat
    {
        std::string type;
        int attack;
        int defense;
        int agillity;
        int health;
    };
    CardDeck::~CardDeck()
    {
        for (auto it : m_Cards)
        {
            while (!it.second.empty())
            {
                Card* card = it.second.front();
                it.second.pop();
                delete card;
            }
        }
    }
    void CardDeck::LoadDeck(const std::string& filePath)
    {
        std::ifstream file;
        file.open(filePath);

        if (file.is_open())
        {    
            while (!file.eof())
            {
                CardFormat card;
                std::string line;
           
                file >> card.type;
                file >> card.attack;
                file >> card.defense;
                file >> card.agillity;
                file >> card.health;

                Card* playCard = nullptr;
                if (card.type == "Warrior")
                {
                    playCard = new WarriorCard(card.attack,card.defense,card.agillity,card.health);
                    m_Cards[Card::Warrior].push(playCard);
                }
                else if (card.type == "Mage")
                {    
                    playCard = new MageCard(card.attack,card.defense,card.agillity,card.health);
                    m_Cards[Card::Mage].push(playCard);
                }
                else if (card.type == "Archer")
                {
                    playCard = new ArcherCard(card.attack,card.defense,card.agillity,card.health);
                    m_Cards[Card::Archer].push(playCard);
                }
                else if (card.type == "Rogue")
                {
                    playCard = new RogueCard(card.attack,card.defense,card.agillity,card.health);
                    m_Cards[Card::Rogue].push(playCard);
                }
                else
                {
                    std::cout << "Unknown card type" <<std::endl;
                    assert(false);
                }
                
            }
        }
        else
        {
            std::cout << "Could not open the file "<< filePath << std::endl;   
        }
    }

    void CardDeck::Render(const Vec2& pos)
    {
        std::stringstream ss;
        ss << "Warrior ";
        ss << (int)m_Cards[Card::Warrior].size();
        ss << " Mage ";
        ss << (int)m_Cards[Card::Mage].size();
        ss << " Archer ";
        ss << (int)m_Cards[Card::Archer].size();
        ss << " Rogue ";
        ss << (int)m_Cards[Card::Rogue].size();

        Renderer::SetPixelSequence(pos,ss.str());
    }

    void CardDeck::InsertCard(Card* card)
    {
        auto type = card->GetType();
        m_Cards[type].push(card);
    }
    Card* CardDeck::GetCard(Card::Type type)
    {
        if (!m_Cards[type].empty())
        {
            Card* card = m_Cards[type].front();
            m_Cards[type].pop();
            return card;
        }   
        return nullptr; 
    }

    
    bool CardDeck::IsEmpty()
    {
       for (auto it : m_Cards)
       {
           if (!it.second.empty())
            return false;
       }
       return true;
    }
}