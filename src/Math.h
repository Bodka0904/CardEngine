#pragma once

namespace Dot{
    struct Vec2
    {
        Vec2(int X,int Y)
        :
            x(X),y(Y)
        {}
        int x;
        int y;
              
        bool operator==(const Vec2& other) const
        {
            return (x == other.x && y == other.y);
        }
        Vec2& operator =(const Vec2& other)
        {
            x = other.x;
            y = other.y;
            return *this;
        }
        Vec2& operator +=(const Vec2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }
        Vec2& operator -= (const Vec2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        Vec2 operator +(const Vec2& other)
        {
            return Vec2(x + other.x, y + other.y);
        }
        Vec2 operator -(const Vec2& other)
        {
            return Vec2(x - other.x, y - other.y);
        }
    };
}