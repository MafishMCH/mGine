#pragma once

#include "engine/basic/drawable.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Framework
{
public:
    SDL_Surface*img;
    // Contructor which initialize the parameters.
    Framework(int height_, int width_);
    Framework(){};

    // Destructor
    ~Framework();
    void update();

    void begin();
    void end();
    void draw(SDL_Texture* img);
    void draw(Drawable&obj);

    SDL_Texture* loadImage(std::string path);
private:
    int height;     // Height of the window
    int width;      // Width of the window

    SDL_Surface *screen;
    SDL_Renderer *renderer = NULL;      // Pointer for the renderer
    SDL_Window *window = NULL;      // Pointer for the window
};