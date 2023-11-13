#pragma once

#include <SDL2/SDL.h>

#include "vectors.h"

struct Rectangle
{
    float x = 0.f, y = 0.f;
    float width = 0.f, height = 0.f;

    Rectangle(float x = 0.f, float y = 0.f, float width = 0.f, float height = 0.f);
    Rectangle(Vector2 position, Vector2 size);

    Vector2 GetPosition();
    Vector2 GetSize();

    void SetPosition(float x, float y);
    void SetSize(float width, float height);
};

struct Circle
{
    float x = 0.f, y = 0.f, radius = 0.f;

    Circle(float x = 0.f, float y = 0.f, float radius = 0.f);

    Vector2 GetPosition();
    void SetPosition(float x, float y);

    float GetRadius();
    void SetRadius(float radius);
};