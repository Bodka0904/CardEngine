#pragma once

namespace Dot {
    class Card
    {
    public:
        virtual ~Card();
        
        enum Type
        {
            Warrior,
            Mage,
            Archer,
            Rogue,
            Num_Types
        };
        

        virtual void Update(float percents, int boost) = 0;
        virtual int ReceiveDamage(Type enemyType,int damage) = 0;
        virtual int Attack() = 0;

        virtual Type GetType() = 0;
        virtual bool Dead() = 0;
    
    };


    class WarriorCard : public Card
    {
    public:
        WarriorCard(int attack,int defense,int agillity,int health);
        WarriorCard(const WarriorCard& other);
        virtual void Update(float percents, int boost) override;
        virtual int ReceiveDamage(Type enemyType,int damage) override;
        virtual int Attack() override;

        virtual Type GetType() override { return m_Type; }
        virtual bool Dead() override { return m_Health <= 0;}
    private:
        Type m_Type;

        
        int m_Attack;
        int m_Defense;
        int m_Agillity;
        int m_Health;
    };


    class MageCard : public Card
    {
    public:
        MageCard(int attack,int defense,int agillity,int health);
        MageCard(const MageCard& other);

        virtual void Update(float percents, int boost) override;
        virtual int ReceiveDamage(Type enemyType,int damage) override;
        virtual int Attack() override;

        virtual Type GetType() override { return m_Type; }
        virtual bool Dead() override { return m_Health <= 0;}
    private:
        Type m_Type;

        
        int m_Attack;
        int m_Defense;
        int m_Agillity;
        int m_Health;

    };


    class ArcherCard : public Card
    {
    public:
        ArcherCard(int attack,int defense,int agillity,int health);
        ArcherCard(const ArcherCard& other);

        virtual void Update(float percents, int boost) override;
        virtual int ReceiveDamage(Type enemyType,int damage) override;
        virtual int Attack() override;

        virtual Type GetType() override { return m_Type; }
        virtual bool Dead() override { return m_Health <= 0;}
    private:
        Type m_Type;

        
        int m_Attack;
        int m_Defense;
        int m_Agillity;
        int m_Health;

    };

    class RogueCard : public Card
    {
    public:
        RogueCard(int attack,int defense,int agillity,int health);
        RogueCard(const RogueCard& other);

        virtual void Update(float percents, int boost) override;
        virtual int ReceiveDamage(Type enemyType,int damage) override;
        virtual int Attack() override;

        virtual Type GetType() override { return m_Type; }
        virtual bool Dead() override { return m_Health <= 0;}
   private:
        Type m_Type;

        
        int m_Attack;
        int m_Defense;
        int m_Agillity;
        int m_Health;

    };
}