#include <vector>
#include <string.h>
#include <chrono>

namespace Dot
{   
    class Window
    {
        using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
    public:
        Window(int width, int height,float frameLen);
        ~Window();

        
        void BeginFrame();
        void EndFrame();
        
        void SetPixel(int x,int y);
        void Resize(int width,int height);
    
    private:
        void render();
        void clear();
    private:
        int m_Width;
        int m_Height;
        int m_FrameCounter = 0;
        
        float m_FrameLength;
        float m_CurrentTime;

        TimePoint m_Start;
        TimePoint m_End;

        std::vector<char*> m_Pixels;

        static constexpr int sc_MaxWidth = 1000;
        static constexpr int sc_MaxHeight = 1000; 
    };
}