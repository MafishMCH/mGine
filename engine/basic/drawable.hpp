#pragma once
#include "engine/basic/shapes.hpp"

#include <SDL.h>
#include <SDL_image.h>

class Drawable
{
private:
    SDL_Texture * texture;
public:
    Rectangle r;
    float angle = 0.0f;
    float scale = 1.0f;
    Drawable(){};
    Drawable(SDL_Texture*img, const Rectangle&rectangle);
    Drawable(SDL_Texture*img, int x, int y);
    Drawable(SDL_Texture*img, int x, int y, int w, int h);
    Drawable(SDL_Texture*img, const Vector2&pos);
    Drawable(SDL_Texture*img, const Vector2&pos, const Vector2&dim);
    ~Drawable();

    SDL_Texture*getTexture();
};
