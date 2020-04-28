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
                    m_Cards.insert({Card::Warrior,playCard});
                }
                else if (card.type == "Mage")
                {    
                    playCard = new MageCard(card.attack,card.defense,card.agillity,card.health);
                    m_Cards.insert({Card::Mage,playCard});
                }
                else if (card.type == "Archer")
                {
                    playCard = new ArcherCard(card.attack,card.defense,card.agillity,card.health);
                    m_Cards.insert({Card::Archer,playCard});
                }
                else if (card.type == "Rogue")
                {
                    playCard = new RogueCard(card.attack,card.defense,card.agillity,card.health);
                    m_Cards.insert({Card::Rogue,playCard});
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
        ss << "Warriors ";
        ss << (int)m_Cards.count(Card::Warrior);

        Renderer::SetPixelSequence(pos,ss.str());
        Renderer::SetPixelSequence(Vec2(pos.x,pos.y+1),"Mages");
        Renderer::SetPixelSequence(Vec2(pos.x,pos.y+2),"Archers");
        Renderer::SetPixelSequence(Vec2(pos.x,pos.y+3),"Rogues");
    }
}