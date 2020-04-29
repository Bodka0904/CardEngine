#pragma once
#include "Math.h"

namespace Dot {
    class Animation
    {
    public:
        Animation(float animLength);
        virtual bool Update(const Vec2& pos,float dt) = 0;
    protected:
        float m_Length;
    };




    class ExplosionAnimation : public Animation
    {
    public:
        ExplosionAnimation(float animLegth);


        virtual bool Update(const Vec2& pos,float dt) override;
    private:
        float m_CurrentTime;
    };


    class CardMoveAnimation : public Animation
    {
    public:
        CardMoveAnimation(float animLength,const Vec2& velocity,const Vec2& size);


        virtual bool Update(const Vec2& pos,float dt) override;
    private:
        Vec2 m_Velocity;
        Vec2 m_Size;
        float m_CurrentTime;
    };
}