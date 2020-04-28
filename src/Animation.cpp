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

    bool ExplosionAnimation::Update(float dt)
    {
        m_CurrentTime += dt*2;
        Renderer::DrawCircle(Vec2(50,15),(int)m_CurrentTime*2,'#');

        if (m_CurrentTime >= m_Length)
        {
            m_CurrentTime = 0.0f;
            return true;
        }
        return false;
    }
}