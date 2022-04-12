#include "framework.hpp"

#include <iostream>

Framework::Framework(std::string windowName, int _width, int _height)
{
    width = _width;
    height = _height;
    window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1920, 1080);    
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
}
Framework::~Framework(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void Framework::update()
{
    SDL_RenderPresent(renderer);
}
void Framework::begin()
{
    SDL_SetRenderTarget(renderer, screen);
    SDL_RenderClear(renderer);   
}
void Framework::end()
{
    SDL_RenderPresent(renderer);
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopyF(renderer,screen, NULL,NULL);
    SDL_RenderPresent(renderer);
}

SDL_Texture* Framework::loadImage(std::string path)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, path.c_str());
	return texture;
}

void Framework::draw(SDL_Texture*img)
{
    SDL_RenderCopyF(renderer, img, NULL, NULL);
}
void Framework::draw(Drawable&obj)
{
    SDL_FRect*drawRectangle;
    if(obj.scale != 1.0f)
    {
        drawRectangle = new SDL_FRect();
        drawRectangle->x = obj.r.p.x;
        drawRectangle->y = obj.r.p.y;
        drawRectangle->w = obj.scale * obj.r.dim.x;
        drawRectangle->h = obj.scale * obj.r.dim.y;
    }
    else
        drawRectangle = obj.r.toSDL_FRect();

    SDL_RenderCopyExF(renderer, obj.getTexture(), NULL, drawRectangle, obj.angle, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
}
