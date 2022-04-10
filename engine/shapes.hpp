#include <SDL.h>

class Vector2
{
public:
    int x = 0;
    int y = 0;
    Vector2()
    {
        x = 0;
        y = 0;
    }
    Vector2(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    Vector2 operator+(const Vector2& b)
    {
        return Vector2(this->x + b.x, this->y + b.y);
    }
    Vector2 operator-(const Vector2& b)
    {
        return Vector2(this->x - b.x, this->y - b.y);
    }
    Vector2 operator*(const float a)
    {
        return Vector2(this->x * a, this->y * a);
    }
    Vector2 operator/(const float a)
    {
        return Vector2(this->x / a, this->y / a);
    }
    static Vector2 distanceSquared(const Vector2&from, const Vector2&to)
    {
        return Vector2(to.x - from.x, to.y - from.y);
    }
};

class Rectangle
{
public:
    Vector2 p;
    Vector2 dim;
    Rectangle(int _x, int _y, int _width, int _heigh)
    {
        p.x = _x;
        p.y = _y;
        dim.x = _width;
        dim.y = _heigh;
    }
    SDL_Rect toSDLRect()
    {
        SDL_Rect r;
        r.x = p.x;
        r.y = p.y;
        r.w = dim.x;
        r.h = dim.y;
        return r;
    }
};
