#include "window.h"

#include <stdexcept>
#include <string>

Window::Window()
{
    int SDL_Flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER;
    if (SDL_Init(SDL_Flags) < 0)
        throw std::runtime_error(std::string("Couldn't start SDL library, ERROR: ") + std::string(SDL_GetError()));

    window = SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL)
        throw std::runtime_error(std::string("Couldn't create a window, ERROR: ") + std::string(SDL_GetError()));

    SDL_Log("Created Window!");
}

Window::~Window()
{
    SDL_DestroyWindow(window);

    SDL_Log("Destroyed Window!");

    SDL_Quit();
}

void Window::SetTitle(const std::string &title)
{
    SDL_SetWindowTitle(window, title.c_str());
}

void Window::SetSize(const int width, const int height)
{
    SDL_SetWindowSize(window, width, height);
}

SDL_Window *Window::GetWindowPointer()
{
    return window;
}

Window &Window::GetInstance()
{
    static Window instance;
    return instance;
}