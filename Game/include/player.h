#pragma once

#include "canvas.h"
#include "texture.h"
#include "texture_loader.h"
#include "keyboard.h"
#include "vectors.h"

class Player
{
    TextureLoader &loader = TextureLoader::GetInstance();
    Canvas &canvas = Canvas::GetInstance();
    Keyboard &keyboard = Keyboard::GetInstance();

    Vector2 position = {100.0f, 100.0f};
    Texture2D sprite = loader.GetTexture("assets/sprites/slimy.png");

    float speed = 100.0f;

public:
    Player();
    ~Player();

    void Update();
    void Render();
};