#pragma once

#include <string>

#include <SDL2/SDL.h>

struct Texture2D
{
    SDL_Texture *texture;

    Texture2D() = default;
    Texture2D(const std::string &filePath);
    ~Texture2D();

private:
    std::string filePath = "";
};

struct CacheTexture
{
    Texture2D texture;
    float loadedTime = 0.0f;
    int count = 1;

    CacheTexture(const std::string &filePath) : texture(filePath)
    {
    }

    ~CacheTexture()
    {
        SDL_Log("Cache Texture Deleted!");
    }
};