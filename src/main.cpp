#include "engine/framework.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

void init();
void update();
void draw();

Framework*fw;


int main(int argc, char * argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Event event;

    fw = new Framework(800,600);

    Drawable x(fw->loadImage("./content/blob.png"), Vector2(10,10));

    init();
    float f = 0.0f;
    while(!(event.type == SDL_QUIT))
    {
        SDL_PollEvent(&event);  // Catching the poll event.

        fw->begin();
        fw->draw(x);
        fw->end();

        SDL_Delay(10);  // setting some Delay
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