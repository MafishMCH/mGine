#include "mgine/mgine.hpp"
#include "mgine/debug/console.hpp"
#include "mgine/debug/performance.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>

void init();
void update();
void draw();

Mgine*fw;


int main(int argc, char * argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_Event event;

    fw = new Mgine("mgine DEMO", 1280, 720);

    std::vector<Drawable> items;
    for(int i = 0; i < 5; i++)
        items.emplace_back(fw->loadImage("./content/blob.png"), Vector2(i*32, 32));

    init();
    while(!(event.type == SDL_QUIT))
    {
        SDL_PollEvent(&event);  // Catching the poll event.

        const Uint8* keys = SDL_GetKeyboardState(NULL);
        if(keys[SDL_SCANCODE_GRAVE])
            fw->toggleFlag(MgineFlags::SHOW_CONSOLE);


        fw->begin();

        int h = 0;

        fw->draw(items[0], SDL_COLOR_WHITE);
        fw->draw(items[1], SDL_COLOR_RED);
        fw->draw(items[2], SDL_COLOR_GREEN);
        fw->draw(items[3], SDL_COLOR_BLUE);
        fw->draw(items[4], SDL_COLOR_SEMITRANSPARENT);


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