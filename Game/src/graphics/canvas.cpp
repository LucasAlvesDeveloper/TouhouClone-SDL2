#include "canvas.h"

#include <stdexcept>
#include <string>

Canvas::Canvas()
{
    if (IMG_Init(IMG_INIT_PNG) == 0)
        throw std::runtime_error(std::string("Couldn't init SDL_image library, ERROR: ") + std::string(IMG_GetError()));

    renderer = SDL_CreateRenderer(Window::GetInstance().GetWindowPointer(), -1, SDL_RENDERER_ACCELERATED);

    SDL_Log("Canvas Created!");
}

Canvas::~Canvas()
{
    SDL_DestroyRenderer(renderer);
    SDL_Log("Canvas Destroyed");
    IMG_Quit();
}

SDL_Renderer *Canvas::GetRenderer()
{
    return renderer;
}

void Canvas::SetResolution(const int width, const int height)
{
    SDL_RenderSetLogicalSize(renderer, width, height);
}

void Canvas::ClearBackground(Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

void Canvas::FlipFrame()
{
    SDL_RenderPresent(renderer);
}

void Canvas::DrawTexture(Texture2D &texture, const Rectangle *src, const Rectangle *dest)
{
    SDL_Rect *srcRenderRect = NULL;
    SDL_FRect *destRenderRect = NULL;
    if (src != NULL)
    {
        srcRenderRect = new SDL_Rect();
        srcRenderRect->x = static_cast<int>(src->x);
        srcRenderRect->y = static_cast<int>(src->y);
        srcRenderRect->w = static_cast<int>(src->width);
        srcRenderRect->h = static_cast<int>(src->height);
    }

    if (dest != NULL)
    {
        destRenderRect = new SDL_FRect();
        destRenderRect->x = dest->x;
        destRenderRect->y = dest->y;
        destRenderRect->w = dest->width;
        destRenderRect->h = dest->height;
    }

    SDL_RenderCopyF(renderer, texture.texture, srcRenderRect, destRenderRect);
    delete srcRenderRect;
    delete destRenderRect;
}

void Canvas::DrawRectangleFilled(int x, int y, int width, int height, Color color)
{
    SDL_Rect rect{x, y, width, height};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

Canvas &Canvas::GetInstance()
{
    static Canvas instance;
    return instance;
}