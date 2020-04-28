#include "Renderer.h"
#include "Core.h"


#include <stdlib.h>
#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>


namespace Dot
{
    Renderer *Renderer::s_Instance = NULL;

    Renderer::Renderer(float frameLen)
       : 
       m_CurrentTime(frameLen),
       m_FrameLength(frameLen)
    {
        printf("\033[8;%d;%dt",sc_Height,sc_Width);
        printf("\033[1;%dm", ToUnderlying(BackgroundColor::COLOR_BLACK_B));
        
        system("clear");
        memset((char*)m_Pixels,' ',sc_Height*sc_Width);
        std::cout.write(&m_Pixels[0][0], sc_Height * sc_Width); 
    }
    
    void Renderer::Init(float frameLen)
    {
        if (!s_Instance)
            s_Instance = new Renderer(frameLen);
    }
    void Renderer::Shutdown()
    {
        printf("\033[1;%dm", ToUnderlying(BackgroundColor::COLOR_BLACK_B));
        delete s_Instance;
    }
    void Renderer::SetBackground(BackgroundColor color)
    {
        printf("\033[1;%dm", ToUnderlying(color));
        
        for (int i = 0; i < s_Instance->sc_Height;++i)  
            std::cout << s_Instance->m_Pixels[i] << std::endl;
                     
    }
    void Renderer::Update(float dt)
    {
        s_Instance->m_CurrentTime -= dt;
        
        // Render new frame
        if (s_Instance->m_CurrentTime <= 0.0f)
        {        
            s_Instance->render();
            // Debug purpose //
            s_Instance->m_FrameCounter++;
            //std::cout << s_Instance->m_FrameCounter<<std::endl;
            ///////////////////
            s_Instance->m_CurrentTime = s_Instance->m_FrameLength; 
        }     
    } 
    
    void Renderer::SetPixel(const Vec2& pixel, char c)
    {
        if (pixel.x < sc_Width && pixel.x >= 0
         && pixel.y < sc_Height && pixel.y >= 0)
            s_Instance->m_Pixels[pixel.y][pixel.x] = c;
    }
    void Renderer::SetPixelSequence(const Vec2& pixel,const std::string& text)
    {
        int counter = 0;
        for (int i = pixel.x; i < pixel.x + (int)text.size();++i)
        {  
            SetPixel(Vec2(i,pixel.y),text[counter]);
            counter++;
        }
    }
    void Renderer::DrawQuad(const Vec2& l1,const Vec2& l2, char c)
    {
        for (int y = l1.y; y < l2.y; ++y)
        {
            for (int x = l1.x; x < l2.x; ++x)
            {
                s_Instance->SetPixel(Vec2(x,y),c);
            }
        }
    }
    int pth (int x,int y)  
    {
        return sqrt (pow(x,2)+pow(y,2));
    }
    void Renderer::DrawCircle(const Vec2& pos,int radius, char c)
    {
        int length = radius * 1.5;
        for (int y = -radius; y <= radius; y += 2)  
        {
            for (int x = -length; x <= length; x++)  
            {
                if (pth(x,y) == radius) 
                    s_Instance->SetPixel(Vec2(x + pos.x,y + pos.y),c);
            }
        }
    }

    void Renderer::render()
    {    
        std::cout.write(&m_Pixels[0][0], sc_Height * sc_Width); 
        std::cout.flush();
        memset((char*)m_Pixels,' ',sc_Height*sc_Width);
    }
   
} 