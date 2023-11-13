#include "player.h"

#include "timer.h"

Player::Player()
{
    SDL_Log("Player Created");
}

Player::~Player()
{
    SDL_Log("Player Destroyed");
}

void Player::Update()
{
    Vector2 direction;
    Vector2 velocity;

    if (keyboard.IsKeyHeld(Key::UP))
        direction.y -= 1.0f;
    if (keyboard.IsKeyHeld(Key::DOWN))
        direction.y += 1.0f;
    if (keyboard.IsKeyHeld(Key::LEFT))
        direction.x -= 1.0f;
    if (keyboard.IsKeyHeld(Key::RIGHT))
        direction.x += 1.0f;

    velocity = direction.Normalize() * speed * Timer::GetDeltaTime();

    if (keyboard.IsKeyHeld(Key::LSHIFT))
        velocity /= 2.0f;

    position += velocity;
}

void Player::Render()
{
    Rectangle dest(position, {64.0f, 64.0f});
    canvas.DrawTexture(sprite, NULL, &dest);
}