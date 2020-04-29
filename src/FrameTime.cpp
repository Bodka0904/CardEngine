#include "FrameTime.h"


namespace Dot{

    FrameTime::FrameTime()
    {
        m_Start = std::chrono::high_resolution_clock::now();
        m_End = std::chrono::high_resolution_clock::now();
    }

    void FrameTime::StartFrame()
    {
        m_Start = std::chrono::high_resolution_clock::now();
    }

    void FrameTime::EndFrame()
    {
        m_End = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_Start).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(m_End).time_since_epoch().count();     
        float time = (end - start);
        m_LastFrameTime = time;

        
    }
}