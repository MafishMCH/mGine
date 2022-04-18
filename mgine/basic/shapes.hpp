#pragma once

#include <SDL.h>

class Vector2
{
public:
    float x = 0;
    float y = 0;
    Vector2()
    {
        x = 0;
        y = 0;
    }
    Vector2(float _x, float _y)
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
    SDL_FRect*sdlRect;
    Rectangle(){};
    Rectangle(float _x, float _y, float _width, float _heigh)
    {
        p.x = _x;
        p.y = _y;
        dim.x = _width;
        dim.y = _heigh;
    }
    SDL_FRect*toSDL_FRect()
    {
        sdlRect = new SDL_FRect();
        sdlRect->x = p.x;
        sdlRect->y = p.y;
        sdlRect->w = dim.x;
        sdlRect->h = dim.y;
        return sdlRect;
    }
};
