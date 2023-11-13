#pragma once

#pragma once

struct Vector2
{
    float x = 0, y = 0;

    Vector2() = default;

    Vector2(float x, float y) : x(x), y(y)
    {
    }

    Vector2 &ToInt();
    Vector2 &Normalize();

    Vector2 &operator+(Vector2 &other);
    Vector2 &operator-(Vector2 &other);
    Vector2 &operator*(Vector2 &other);
    Vector2 &operator/(Vector2 &other);

    Vector2 &operator*(float scale);
    Vector2 &operator/(float scale);

    Vector2 &operator+=(Vector2 &other);
    Vector2 &operator-=(Vector2 &other);
    Vector2 &operator*=(Vector2 &other);
    Vector2 &operator/=(Vector2 &other);

    Vector2 &operator*=(float scale);
    Vector2 &operator/=(float scale);
};
