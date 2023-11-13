#pragma once

class InputManager
{
public:
    bool PollEvents();

private:
    InputManager();
    ~InputManager();

public:
    static InputManager &GetInstance();

    InputManager(InputManager const &) = delete;
    void operator=(InputManager const &) = delete;
};