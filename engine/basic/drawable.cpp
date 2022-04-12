#include "drawable.hpp"
#include <iostream>
Drawable::~Drawable()
{

}

Drawable::Drawable(SDL_Texture*img, const Rectangle&rectangle)
{
    texture = img;
    r = Rectangle(r);
}
Drawable::Drawable(SDL_Texture*img, const Vector2&pos)
{
    texture = img;
    r.p = Vector2(pos);
    int x,y;
    SDL_QueryTexture(texture, NULL, NULL, &x, &y);
    r.dim.x = x;
    r.dim.y = y;
}
Drawable::Drawable(SDL_Texture*img, const Vector2&pos, const Vector2&dim)
{
    texture = img;
    r.p = Vector2(pos);
    r.dim = Vector2(dim);
}
SDL_Texture* Drawable::getTexture()
{
    return texture;
}
