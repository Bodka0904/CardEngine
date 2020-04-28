#pragma once


namespace Dot {
    class Animation
    {
    public:
        Animation(float animLength);
        virtual bool Update(float dt) = 0;
    protected:
        float m_Length;
    };




    class ExplosionAnimation : public Animation
    {
    public:
        ExplosionAnimation(float animLegth);


        virtual bool Update(float dt) override;
    private:
        float m_CurrentTime;
    };
}