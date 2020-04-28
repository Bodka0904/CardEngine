#pragma once

namespace Dot {
    class Card
    {
    public:
        Card(int attack,int defense,int agillity,int health);
        virtual ~Card();
        
        enum Type
        {
            Warrior,
            Mage,
            Archer,
            Rogue
        };


        virtual void Update(float percents, int boost) = 0;
        virtual void ReceiveDamage(Type enemyType,int damage) = 0;
        virtual int Attack() = 0;

        virtual Type GetType() { return m_Type; }
        bool Dead() { return m_Health <= 0;}
    protected:
        Type m_Type;

        
        int m_Attack;
        int m_Defense;
        int m_Agillity;
        int m_Health;
    };


    class WarriorCard : public Card
    {
    public:
        WarriorCard(int attack,int defense,int agillity,int health);
        virtual void Update(float percents, int boost) override;
        virtual void ReceiveDamage(Type enemyType,int damage) override;
        virtual int Attack() override;
    };


    class MageCard : public Card
    {
    public:
        MageCard(int attack,int defense,int agillity,int health);
        virtual void Update(float percents, int boost) override;
        virtual void ReceiveDamage(Type enemyType,int damage) override;
        virtual int Attack() override;
    private:

    };


    class ArcherCard : public Card
    {
    public:
        ArcherCard(int attack,int defense,int agillity,int health);
        virtual void Update(float percents, int boost) override;
        virtual void ReceiveDamage(Type enemyType,int damage) override;
        virtual int Attack() override;
    private:

    };

    class RogueCard : public Card
    {
    public:
        RogueCard(int attack,int defense,int agillity,int health);
        virtual void Update(float percents, int boost) override;
        virtual void ReceiveDamage(Type enemyType,int damage) override;
        virtual int Attack() override;
    private:

    };
}