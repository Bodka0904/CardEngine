#pragma once
#include <chrono>

namespace Dot
{
    class FrameTime
    {
        using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
    public:
        FrameTime();
        void StartFrame();
        void EndFrame();

        float GetSeconds() { return m_LastFrameTime * 0.000001;}
        float GetMiliseconds() {return m_LastFrameTime * 0.001;}
    private:
        float m_LastFrameTime = 0.0f;

        TimePoint m_Start;
        TimePoint m_End;
    };
} 
