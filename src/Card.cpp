#include "Card.h"
#include "Renderer.h"

#include <random>
#include <string>
#include <sstream>

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
   
    
    Card::~Card()
    {

    }
    
    WarriorCard::WarriorCard(int attack, int defense,int agillity,int health)
         :
        m_Type(Warrior),
        m_Attack(attack),
        m_Defense(defense),
        m_Agillity(agillity),
        m_Health(health)
    {
    }

    WarriorCard::WarriorCard(const WarriorCard& other)
        :
        m_Type(Warrior),
        m_Attack(other.m_Attack),
        m_Defense(other.m_Defense),
        m_Agillity(other.m_Agillity),
        m_Health(other.m_Health)
    {
    }
    void WarriorCard::Update(float percents, int boost)
    {
        if (PercentCheckRandom(percents))
        {
            m_Defense += boost;
        }
    }

    int WarriorCard::ReceiveDamage(Type enemyType,int damage)
    {
        int oldHealth =m_Health;
        if (enemyType == Mage)
        {
            m_Health -= RandomNumber(0,damage/m_Defense);
        }
        else if (enemyType == Rogue)
        {
            m_Health -= RandomNumber(0, damage/2);
        }
        else if (enemyType == Archer)
        {
            m_Health -= RandomNumber(0,damage);
        }
        else if (enemyType == Warrior)
        {
            m_Health -= RandomNumber(0,damage/m_Defense);
        }
        return oldHealth - m_Health;
    }

    int WarriorCard::Attack()
    {   
        int attack = m_Attack;
        if (PercentCheckRandom(m_Agillity))
        {
            attack += 5;
        }
        return RandomNumber(0,attack);
    }

    MageCard::MageCard(int attack, int defense,int agillity,int health)
        :
        m_Type(Mage),
        m_Attack(attack),
        m_Defense(defense),
        m_Agillity(agillity),
        m_Health(health)
    {
    }
    MageCard::MageCard(const MageCard& other)
        :
        m_Type(Mage),
        m_Attack(other.m_Attack),
        m_Defense(other.m_Defense),
        m_Agillity(other.m_Agillity),
        m_Health(other.m_Health)
    {
    }
    void MageCard::Update(float percents, int boost)
    {
        if (PercentCheckRandom(percents))
        {
            m_Attack += boost;
        }
    }

    int MageCard::ReceiveDamage(Type enemyType,int damage)
    {
        int oldHealth = m_Health;
        if (enemyType == Mage)
        {
            m_Health = RandomNumber(0, damage);
        }
        else if (enemyType == Rogue)
        {
            m_Health -= RandomNumber(0, (damage*2)/m_Defense);
        }
        else if (enemyType == Archer)
        {
            m_Health -= RandomNumber(0,damage/m_Defense);
        }
        else if (enemyType == Warrior)
        {
            m_Health -= RandomNumber(0,damage/m_Defense);
        }
        return oldHealth - m_Health;
    }

    int MageCard::Attack()
    {
        int attack = m_Attack;
        if (PercentCheckRandom(m_Agillity))
        {
            attack += 5;
        }
        return RandomNumber(0,attack);
    }

    ArcherCard::ArcherCard(int attack, int defense,int agillity,int health)
         :
        m_Type(Archer),
        m_Attack(attack),
        m_Defense(defense),
        m_Agillity(agillity),
        m_Health(health)
    {
    }

    ArcherCard::ArcherCard(const ArcherCard& other)
        :
        m_Type(Archer),
        m_Attack(other.m_Attack),
        m_Defense(other.m_Defense),
        m_Agillity(other.m_Agillity),
        m_Health(other.m_Health)
    {
    }
    
    void ArcherCard::Update(float percents, int boost)
    {
        if (PercentCheckRandom(percents))
        {
            m_Agillity += boost;
        }
    }

    int ArcherCard::ReceiveDamage(Type enemyType,int damage)
    {
        int oldHealth = m_Health;
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
        return oldHealth - m_Health;
    }
    
    int ArcherCard::Attack()
    {
        int attack = m_Attack;
        if (PercentCheckRandom(m_Agillity))
        {
            attack += 5;
        }
        return RandomNumber(0,attack);
    }

    RogueCard::RogueCard(int attack, int defense,int agillity,int health)
         :
        m_Type(Rogue),
        m_Attack(attack),
        m_Defense(defense),
        m_Agillity(agillity),
        m_Health(health)
    {
    }
    RogueCard::RogueCard(const RogueCard& other)
        :
        m_Type(Rogue),
        m_Attack(other.m_Attack),
        m_Defense(other.m_Defense),
        m_Agillity(other.m_Agillity),
        m_Health(other.m_Health)
    {
    }
    void RogueCard::Update(float percents, int boost)
    {
        if (PercentCheckRandom(percents))
        {
            m_Attack += (int)floor((double)boost/2.0f);
            m_Agillity += (int)floor((double)boost/2.0f);
        }
    }
    int RogueCard::ReceiveDamage(Type enemyType,int damage)
    {
        int oldHealth = m_Health;
        if (enemyType == Mage)
        {
            m_Health -= RandomNumber(0,damage/m_Defense);
        }
        else if (enemyType == Rogue)
        {
            m_Health--;
        }
        else if (enemyType == Archer)
        {  
            m_Health -= RandomNumber(0, damage/m_Defense);
        }
        else if (enemyType == Warrior)
        {
            m_Health -= RandomNumber(0,damage/m_Defense);
            m_Defense--;
        }
        return oldHealth - m_Health;
    }

    int RogueCard::Attack()
    {
        int attack = m_Attack;
        if (PercentCheckRandom(m_Agillity))
        {
            attack += 5;
        }
        return RandomNumber(0,attack);
    }
}