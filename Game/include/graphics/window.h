#pragma once

#include <string>

#include <SDL2/SDL.h>

class Window
{
public:
    SDL_Window *GetWindowPointer();

    void SetTitle(const std::string &title);
    void SetSize(const int width, const int height);

    // Singleton Stuff
    static Window &GetInstance();

    Window(Window const &) = delete;
    void operator=(Window const &) = delete;

private:
    SDL_Window *window = nullptr;

    Window();
    ~Window();
};