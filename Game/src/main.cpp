#include <stdexcept>
#include <string>

#include <SDL2/SDL.h>

#include "window.h"
#include "canvas.h"
#include "texture_loader.h"
#include "timer.h"
#include "input/keyboard.h"

#include "player.h"

int main(int argc, char *argv[])
{
    auto &window = Window::GetInstance();
    window.SetSize(640, 480);
    window.SetTitle("Touhou Clone - SDL2 Game");

    auto &canvas = Canvas::GetInstance();
    canvas.SetResolution(320, 240);

    auto &textureLoader = TextureLoader::GetInstance();
    auto &keyboardManager = Keyboard::GetInstance();

    Player player;

    float timer = 0;

    bool running = true;

    SDL_Log("Hello!");

    while (running)
    {
        Timer::Tick();
        textureLoader.Update();
        keyboardManager.CleanInput();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                if (!event.key.repeat)
                    keyboardManager.OnKeyDown((Key)event.key.keysym.scancode);
                break;
            case SDL_KEYUP:
                if (!event.key.repeat)
                    keyboardManager.OnKeyUp((Key)event.key.keysym.scancode);
                break;
            }

            if (!running)
                break;
        }

        if (!running)
            break;

        player.Update();

        canvas.ClearBackground(Colors::WHITE);

        canvas.DrawRectangleFilled(0, 0, 320, 240, Colors::BLUE);

        player.Render();

        canvas.FlipFrame();
    }

    return 0;
}