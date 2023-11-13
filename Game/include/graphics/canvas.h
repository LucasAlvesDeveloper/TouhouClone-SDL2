#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.h"
#include "colors.h"
#include "texture.h"
#include "shapes.h"

class Canvas
{
public:
    SDL_Renderer *GetRenderer();

    void SetResolution(const int width, const int height);

    void ClearBackground(Color color = Colors::BLACK);
    void FlipFrame();

    void DrawTexture(Texture2D &texture, const Rectangle *src, const Rectangle *dest);

    void DrawRectangleFilled(int x, int y, int width, int height, Color color = Colors::RED);

    // Singleton Stuff
    static Canvas &GetInstance();

    Canvas(Canvas const &) = delete;
    void operator=(Canvas const &) = delete;

private:
    SDL_Renderer *renderer = nullptr;

    Canvas();
    ~Canvas();
};