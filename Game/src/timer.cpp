#include "timer.h"

#include <SDL2/SDL.h>

namespace Timer
{
    float startFrame, endFrame, deltaTime;

    void Tick()
    {
        endFrame = SDL_GetTicks64();
        deltaTime = (endFrame - startFrame) / 1000.0;
        startFrame = endFrame;
    }

    float GetDeltaTime()
    {
        return deltaTime;
    }
}
