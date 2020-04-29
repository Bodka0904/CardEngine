#include "Animation.h"

#include "Renderer.h"

namespace Dot {
    Animation::Animation(float animLength)
        : m_Length(animLength)
    {}


    ExplosionAnimation::ExplosionAnimation(float animLegth)
        : 
        Animation(animLegth),
        m_CurrentTime(0.0f)

    {}

    bool ExplosionAnimation::Update(const Vec2& pos,float dt)
    {
        m_CurrentTime += dt;
        Renderer::DrawCircle(pos,(int)m_CurrentTime*2,'#');

        if (m_CurrentTime >= m_Length)
        {
            m_CurrentTime = 0.0f;
            return true;
        }
        return false;
    }


    CardMoveAnimation::CardMoveAnimation(float animLength,const Vec2& velocity,const Vec2& size)
        : 
        Animation(animLength),
        m_Velocity(velocity),
        m_Size(size),
        m_CurrentTime(0.0f)
    {}

    bool CardMoveAnimation::Update(const Vec2& pos,float dt)
    {
        m_CurrentTime += dt;
        Vec2 newPos((m_CurrentTime * m_Velocity.x) + pos.x
                   ,(m_CurrentTime * m_Velocity.y) + pos.y);
        Renderer::DrawQuad(newPos,newPos+m_Size,'#');

        if (m_CurrentTime >=m_Length)
        {
            m_CurrentTime = 0.0f;
            return true;
        }
        return false;
    }
}