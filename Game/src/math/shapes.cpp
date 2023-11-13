#include "shapes.h"

Rectangle::Rectangle(float x, float y, float width, float height)
    : x(x), y(y), width(width), height(height)
{
}

Rectangle::Rectangle(Vector2 position, Vector2 size)
    : x(position.x), y(position.y), width(size.x), height(size.y)
{
}

Vector2 Rectangle::GetPosition()
{
    return Vector2(x, y);
}

void Rectangle::SetPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2 Rectangle::GetSize()
{
    return Vector2(width, height);
}

void Rectangle::SetSize(float width, float height)
{
    this->width = width;
    this->height = height;
}

Circle::Circle(float x, float y, float radius)
    : x(x), y(y), radius(radius)
{
}

Vector2 Circle::GetPosition()
{
    return Vector2(x, y);
}

void Circle::SetPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Circle::GetRadius()
{
    return radius;
}

void Circle::SetRadius(float radius)
{
    this->radius = radius;
}