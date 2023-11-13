#pragma once

#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>

#include "keys.h"

class Keyboard
{

public:
    void OnKeyDown(Key key);
    void OnKeyUp(Key key);
    void CleanInput();

    bool IsKeyPressed(Key key);
    bool IsKeyReleased(Key key);
    bool IsKeyHeld(Key key);

private:
    std::unordered_map<Key, bool> pressedKeys;
    std::unordered_map<Key, bool> releasedKeys;
    std::unordered_map<Key, bool> heldKeys;

    Keyboard();
    ~Keyboard();

public:
    static Keyboard &GetInstance();

    Keyboard(Keyboard const &) = delete;
    void operator=(Keyboard const &) = delete;
};