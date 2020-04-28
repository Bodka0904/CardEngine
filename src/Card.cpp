#include "Card.h"
#include "Renderer.h"

#include <random>

namespace Dot {

    static bool PercentCheckRandom(float percent)
    {
        std::mt19937 rng;
        std::uniform_real_distribution<float> dist(0,100);
        return (dist(rng) <= percent);
    }

    static int RandomNumber(int min,int max)
    {
        if (min >= max)
            return 0;

        std::mt19937 rng;
        std::uniform_int_distribution<int> dist(min,max);
        return dist(rng);   
    }
   
    
    Card::Card(int attack,int defense,int agillity,int health)
        :
        m_Attack(attack),
        m_Defense(defense),
        m_Agillity(agillity),
        m_Health(health)
    {}

    Card::~Card()
    {

    }
    
    WarriorCard::WarriorCard(int attack, int defense,int agillity,int health)
        : Card(attack,defense,agillity,health)
    {
        m_Type = Warrior;
    }

    void WarriorCard::Update(float percents, int boost)
    {
        if (PercentCheckRandom(percents))
        {
            m_Defense += boost;
        }
    }

    void WarriorCard::ReceiveDamage(Type enemyType,int damage)
    {
        if (enemyType == Mage)
        {
            m_Health -= RandomNumber(m_Defense,damage);
            m_Defense--;
        }
        else if (enemyType == Rogue)
        {
            m_Health -= RandomNumber(m_Defense, damage*2);
        }
        else if (enemyType == Archer)
        {
            m_Health -= RandomNumber(0,damage);
        }
        else if (enemyType == Warrior)
        {
            m_Health--;
            m_Defense -= 2;
        }
    }

    int WarriorCard::Attack()
    {
        return RandomNumber(0,m_Attack);
    }

    MageCard::MageCard(int attack, int defense,int agillity,int health)
        : Card(attack,defense,agillity,health)
    {
        m_Type = Mage;
    }

    void MageCard::Update(float percents, int boost)
    {
        if (PercentCheckRandom(percents))
        {
            m_Attack += boost;
        }
    }

    void MageCard::ReceiveDamage(Type enemyType,int damage)
    {
        if (enemyType == Mage)
        {
            m_Health--;
            m_Defense -= 2;
        }
        else if (enemyType == Rogue)
        {
            m_Health -= RandomNumber(0, damage*2);
        }
        else if (enemyType == Archer)
        {
            m_Health -= RandomNumber(m_Defense,damage);
        }
        else if (enemyType == Warrior)
        {
            m_Health -= RandomNumber(m_Defense,damage);
            m_Defense--;
        }
    }

    int MageCard::Attack()
    {
        return RandomNumber(0,m_Attack);
    }

    ArcherCard::ArcherCard(int attack, int defense,int agillity,int health)
        : Card(attack,defense,agillity,health)
    {
        m_Type = Archer;
    }


    
    void ArcherCard::Update(float percents, int boost)
    {
        if (PercentCheckRandom(percents))
        {
            m_Agillity += boost;
        }
    }

    void ArcherCard::ReceiveDamage(Type enemyType,int damage)
    {
        if (enemyType == Mage)
        {
            m_Health -= RandomNumber(m_Defense,damage);
        }
        else if (enemyType == Rogue)
        {
            m_Health -= RandomNumber(0, 1);
        }
        else if (enemyType == Archer)
        {  
            m_Health--;
            m_Defense -= 2;
        }
        else if (enemyType == Warrior)
        {
            m_Health -= RandomNumber(m_Defense,damage);
            m_Defense--;
        }
    }
    
    int ArcherCard::Attack()
    {
        return RandomNumber(0,m_Attack+m_Agillity);
    }

    RogueCard::RogueCard(int attack, int defense,int agillity,int health)
        : Card(attack,defense,agillity,health)
    {
        m_Type = Rogue;
    }

    void RogueCard::Update(float percents, int boost)
    {
        if (PercentCheckRandom(percents))
        {
            m_Attack += (int)floor((double)boost/2.0f);
            m_Agillity += (int)floor((double)boost/2.0f);
        }
    }
    void RogueCard::ReceiveDamage(Type enemyType,int damage)
    {
        if (enemyType == Mage)
        {
            m_Health -= RandomNumber(0,damage);
        }
        else if (enemyType == Rogue)
        {
            m_Health--;
            m_Defense -= 2;
        }
        else if (enemyType == Archer)
        {  
            m_Health -= RandomNumber(0, damage*2);
        }
        else if (enemyType == Warrior)
        {
            m_Health -= RandomNumber(m_Defense,damage);
            m_Defense--;
        }
    }

    int RogueCard::Attack()
    {
        return RandomNumber(0,m_Attack+m_Agillity);
    }
}