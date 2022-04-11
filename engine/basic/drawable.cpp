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

Drawable::Drawable(SDL_Texture*img, int x, int y)
{
    if(!img)
        std::cout << "DUPA!" << std::endl;
    texture = img;
    r.p.x = x;
    r.p.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &r.dim.x, &r.dim.y);
}
Drawable::Drawable(SDL_Texture*img, int x, int y, int w, int h)
{
    texture = img;
    r.p.x = x;
    r.p.y = y;
    r.dim.x = w;
    r.dim.y = h;
}
Drawable::Drawable(SDL_Texture*img, const Vector2&pos)
{
    texture = img;
    r.p = Vector2(pos);
    SDL_QueryTexture(texture, NULL, NULL, &r.dim.x, &r.dim.y);
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
