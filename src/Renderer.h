#pragma once
#include "ColorCodes.h"
#include "Math.h"

#include <vector>
#include <string>

namespace Dot
{   
    class Renderer
    {
    public:     
        static void Init(float frameLen);
        static void Shutdown();
        static void SetBackground(BackgroundColor color);

        static void Update(float dt);   
        static void SetPixel(const Vec2& pixel,char c);
        static void SetPixelSequence(const Vec2& pixel,const std::string& text);
        static void DrawQuad(const Vec2& l1,const Vec2& l2, char c);
        static void DrawCircle(const Vec2& pos,int radius, char c);
        
    private:
        Renderer(float frameLen);

        void render();
 
    private:
        int m_FrameCounter = 0;
        
        float m_CurrentTime;
        const float m_FrameLength;

        static int constexpr sc_Width = 100;
        static int constexpr sc_Height = 40;

        char m_Pixels[sc_Height][sc_Width];

        static Renderer* s_Instance;
    };
}