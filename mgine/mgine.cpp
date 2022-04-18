#include "mgine.hpp"
#include "debug/console.hpp"

#include <iostream>


Mgine::Mgine(std::string windowName, int _width, int _height)
{
    width = _width;
    height = _height;
    window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
        SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, 1920, 1080);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    consoleBg = loadImage("./content/mgine/consoleBg.png");
    font = TTF_OpenFont("./content/mgine/montserrat.ttf", 20);
    SDL_SetRenderDrawColor(renderer, 145, 178, 217, 255);
}
Mgine::~Mgine(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void Mgine::toggleFlag(MgineFlags flag)
{
    flags ^= (1 << (int)flag);
}
void Mgine::begin()
{
    SDL_RenderClear(renderer);   
}
void Mgine::end()
{
    drawDebugInfo();
    SDL_RenderPresent(renderer);
}

SDL_Texture* Mgine::loadImage(std::string path)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, path.c_str());
	return texture;
}
void Mgine::draw(SDL_Texture*img)
{
    SDL_RenderCopyF(renderer, img, NULL, NULL);
}
void Mgine::draw(Drawable&obj, const SDL_Color& clr)
{
    if(&clr != &SDL_COLOR_WHITE)
    {
        SDL_SetTextureColorMod(obj.getTexture(), clr.r, clr.g, clr.b);
        SDL_SetTextureAlphaMod(obj.getTexture(), clr.a);
    }
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

    SDL_RenderCopyExF(renderer, obj.getTexture(), NULL, drawRectangle, obj.angle, NULL, SDL_RendererFlip::SDL_FLIP_NONE);\

    if(&clr != &SDL_COLOR_WHITE)
    {
        SDL_SetTextureColorMod(obj.getTexture(), SDL_COLOR_WHITE.r,  SDL_COLOR_WHITE.g,  SDL_COLOR_WHITE.b);
        SDL_SetTextureAlphaMod(obj.getTexture(), SDL_COLOR_WHITE.a);
    }
}

void Mgine::drawDebugInfo()
{
    if((flags >> 1 & 1) == false)
        return;
       
    console.updateDiagnostics();
    SDL_Color textFgColor = { 255, 255, 255 , 255};
    SDL_Color textBgColor = { 0, 0, 0, 255};
    SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped(font, console.getString().c_str(), textFgColor, 600);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect r = {5,5, 100,100};
    SDL_QueryTexture(textTexture, NULL, NULL, &r.w, &r.h);
    SDL_RenderCopy(renderer, consoleBg, NULL, &r);
    SDL_RenderCopy(renderer, textTexture, NULL, &r);

    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}
