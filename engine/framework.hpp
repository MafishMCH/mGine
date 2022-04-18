#pragma once

#include "engine/basic/drawable.hpp"
#include "engine/sdl_colors.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

enum class FrameworkFlags
{
    SHOW_FPS = 0,
    SHOW_CONSOLE = 1,
};

class Framework
{
public:
    // Contructor which initialize the parameters.
    Framework(std::string windowName, int height_, int width_);
    Framework(){};

    // Destructor
    ~Framework();
    void update();

    void begin();
    void end();
    void draw(SDL_Texture* img);
    void draw(Drawable&obj, const SDL_Color&clr = SDL_COLOR_WHITE);

    void toggleFlag(FrameworkFlags flag);

    SDL_Texture* loadImage(std::string path);
private:
    int height;     // Height of the window
    int width;      // Width of the window
    uint32_t flags; //Flags of the engine

    void drawDebugInfo();

    SDL_Texture *screen;
    SDL_Renderer *renderer = NULL;      // Pointer for the renderer
    SDL_Window *window = NULL;      // Pointer for the window

    SDL_Texture*consoleBg;
    TTF_Font* font;

};