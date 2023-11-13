#include "vectors.h"

#include <math.h>

Vector2 &Vector2::ToInt()
{
    x = static_cast<int>(x);
    y = static_cast<int>(y);

    return *this;
}

Vector2 &Vector2::Normalize()
{
    float length = std::sqrt((x * x) + (y * y));

    if (length != 0)
    {
        x /= length;
        y /= length;
    }

    return *this;
}

Vector2 &Vector2::operator+(Vector2 &other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vector2 &Vector2::operator-(Vector2 &other)
{
    x -= other.x;
    y -= other.y;

    return *this;
}

Vector2 &Vector2::operator*(Vector2 &other)
{
    x *= other.x;
    y *= other.y;

    return *this;
}

Vector2 &Vector2::operator/(Vector2 &other)
{
    x /= other.x;
    y /= other.y;

    return *this;
}

Vector2 &Vector2::operator*(float scale)
{
    x *= scale;
    y *= scale;

    return *this;
}

Vector2 &Vector2::operator/(float scale)
{
    x /= scale;
    y /= scale;

    return *this;
}

Vector2 &Vector2::operator+=(Vector2 &other)
{
    x += other.x;
    y += other.y;

    return *this;
}
Vector2 &Vector2::operator-=(Vector2 &other)
{
    x -= other.x;
    y -= other.y;

    return *this;
}
Vector2 &Vector2::operator*=(Vector2 &other)
{
    x *= other.x;
    y *= other.y;

    return *this;
}
Vector2 &Vector2::operator/=(Vector2 &other)
{
    x /= other.x;
    y /= other.y;

    return *this;
}

Vector2 &Vector2::operator*=(float scale)
{
    x *= scale;
    y *= scale;

    return *this;
}

Vector2 &Vector2::operator/=(float scale)
{
    x /= scale;
    y /= scale;

    return *this;
}