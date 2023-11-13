#include "keyboard.h"

Keyboard::Keyboard()
{
    SDL_Log("There is a Key called: %i", Key::A);
}

Keyboard::~Keyboard()
{
}

void Keyboard::OnKeyDown(Key key)
{
    pressedKeys[key] = true;
    heldKeys[key] = true;
}

void Keyboard::OnKeyUp(Key key)
{

    releasedKeys[key] = true;
    heldKeys[key] = false;
}

void Keyboard::CleanInput()
{
    pressedKeys.clear();
    releasedKeys.clear();
}

bool Keyboard::IsKeyPressed(Key key)
{
    return pressedKeys[key];
}

bool Keyboard::IsKeyReleased(Key key)
{
    return releasedKeys[key];
}

bool Keyboard::IsKeyHeld(Key key)
{
    return heldKeys[key];
}

Keyboard &Keyboard::GetInstance()
{
    static Keyboard instance;
    return instance;
}