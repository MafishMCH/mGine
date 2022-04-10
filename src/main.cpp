#include "engine/framework.hpp"
#include "engine/shapes.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

void init();
void update();
void draw();

Framework*fw;

SDL_Texture * img;

int main(int argc, char * argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Event event;

    fw = new Framework(800,600);

    // fw = Framework(800, 600);
    img  = fw->loadImage("./content/blob.png");

    init();
    while(!(event.type == SDL_QUIT))
    {
        SDL_PollEvent(&event);  // Catching the poll event.

        draw();

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
    fw->begin();
    fw->draw(img);
    fw->end();
}