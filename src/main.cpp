#include "engine/framework.hpp"
#include "engine/debug/console.hpp"
#include "engine/debug/performance.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>

void init();
void update();
void draw();

Framework*fw;


int main(int argc, char * argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_Event event;

    fw = new Framework("Terrainer", 1280, 720);

    std::vector<Drawable> items;
    for(int i = 0; i < 60; i++)
        for(int j = 0; j < 34; j++)
            items.emplace_back(fw->loadImage("./content/blob.png"), Vector2(i*32, j*32));


    init();
    while(!(event.type == SDL_QUIT))
    {
        SDL_PollEvent(&event);  // Catching the poll event.

        fw->begin();


        for(auto&item : items)
        {
            item.angle += 0.05f;
            fw->draw(item);
        }

        fw->end();

        SDL_Delay(10);
        Performance::updatePerFrame(SDL_GetTicks());
    }
}

void init()
{

}
void update()
{

}
void draw()
{

}