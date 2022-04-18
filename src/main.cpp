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

std::vector<Drawable> items;    //placeholder for drawable objects

int main(int argc, char * argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_Event event;

    fw = new Mgine("mgine DEMO", 1280, 720);
    init();

    while(!(event.type == SDL_QUIT))
    {
        SDL_PollEvent(&event);  // Catching the poll event.

        const Uint8* keys = SDL_GetKeyboardState(NULL);
        if(keys[SDL_SCANCODE_GRAVE])
            fw->toggleFlag(MgineFlags::SHOW_CONSOLE);

        update();
        draw();

        SDL_Delay(10);
        Performance::updatePerFrame(SDL_GetTicks());
    }
}

void init()
{
    for(int i = 0; i < 5; i++)
        items.emplace_back(fw->loadImage("./content/blob.png"), Vector2(i*32, 32));
}
void update()
{
    static float t = 0.0f;
    t+= 0.01f;
    items[0].r.p.x = 1920/2 + (int)(sinf(t) * 500.0f);
    items[0].r.p.y = 1080/2 + (int)(cosf(t) * 500.0f);
    items[1].r.p.x = 1920/2 + (int)(sinf(t + 1.256) * 500.0f);
    items[1].r.p.y = 1080/2 + (int)(cosf(t + 1.256) * 500.0f);
    items[2].r.p.x = 1920/2 + (int)(sinf(t + 1.256 * 2) * 500.0f);
    items[2].r.p.y = 1080/2 + (int)(cosf(t + 1.256 * 2) * 500.0f);
    items[3].r.p.x = 1920/2 + (int)(sinf(t + 1.256 * 3) * 500.0f);
    items[3].r.p.y = 1080/2 + (int)(cosf(t + 1.256 * 3) * 500.0f);
    items[4].r.p.x = 1920/2 + (int)(sinf(t + 1.256 * 4) * 500.0f);
    items[4].r.p.y = 1080/2 + (int)(cosf(t + 1.256 * 4) * 500.0f);
}
void draw()
{
    fw->begin();

    fw->draw(items[0], SDL_COLOR_WHITE);
    fw->draw(items[1], SDL_COLOR_RED);
    fw->draw(items[2], SDL_COLOR_GREEN);
    fw->draw(items[3], SDL_COLOR_BLUE);
    fw->draw(items[4], SDL_COLOR_SEMITRANSPARENT);

    fw->end();
}