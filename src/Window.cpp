#include "Window.h"

#include <stdlib.h>
#include <iostream>



namespace Dot
{
    Window::Window(int width,int height,float frameLen)
       : m_Width(width),m_Height(height),m_FrameLength(frameLen),m_CurrentTime(frameLen)
    {
        if(m_Width > sc_MaxWidth)
            m_Width = sc_MaxWidth;
        if (m_Height > sc_MaxHeight)
            m_Height = sc_MaxHeight;

        m_Pixels.resize(m_Height);
        for (int i = 0; i < m_Height;++i)
        {
            m_Pixels[i] = new char[m_Width];
            memset(m_Pixels[i],' ',(size_t)m_Width - 1);
            m_Pixels[i][m_Width-1] = 0;
        }
        printf("\e[8;%d;%dt",m_Width,m_Height);
    }
    
    Window::~Window()
    {
        for (size_t i = 0;i < m_Pixels.size();++i)
        {
            delete []m_Pixels[i];
        }
    }
    void Window::clear()
    {     
        system("clear");
        for (size_t i = 0; i < m_Pixels.size();++i)
        {
            memset(m_Pixels[i],' ',(size_t)m_Width-1);
            m_Pixels[i][m_Width-1] = 0;
        }  
    }

    void Window::BeginFrame()
    {
        m_Start = std::chrono::high_resolution_clock::now();
    }
    void Window::EndFrame()
    {
        m_End = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_Start).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(m_End).time_since_epoch().count();     
        float sec = (end - start) * 0.000001f;
        m_CurrentTime -= sec;

        if (m_CurrentTime <= 0.0f)
        {        
            clear();
            render();
            m_FrameCounter++;
            std::cout << m_FrameCounter<<std::endl;
            m_CurrentTime = m_FrameLength; 
        }
    }
    void Window::render()
    {    
        for (size_t i = 0; i < m_Pixels.size();++i)
        {
            SetPixel(i,i);
        }
        for (size_t i = 0; i < m_Pixels.size();++i)
        {        
            std::cout << m_Pixels[i] <<std::endl;
        }            
    }

    void Window::SetPixel(int x,int y)
    {
        m_Pixels[y][x] = '#';
    }
    void Window::Resize(int width,int height)
    {
        m_Height = height;
        m_Width = width;
        m_Pixels.resize(m_Height);
        for (int i = 0; i < m_Height;++i)
        {
            char* tmp = m_Pixels[i];
            m_Pixels[i] = new char[m_Width];
            memcpy(tmp,m_Pixels[i],(size_t)m_Width);
            delete []tmp;
        }
    }
} 