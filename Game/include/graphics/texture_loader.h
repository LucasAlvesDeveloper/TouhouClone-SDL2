#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "texture.h"

class TextureLoader
{
    std::unordered_map<std::string, std::unique_ptr<CacheTexture>> loadedTextures;

private:
    TextureLoader();
    ~TextureLoader();

public:
    Texture2D GetTexture(const std::string &filePath);
    void Unload(const std::string &filePath);

    void Update(const float secondsToDeleteTexture = 5.0f);

public:
    static TextureLoader &GetInstance();

    TextureLoader(TextureLoader const &) = delete;
    void operator=(TextureLoader const &) = delete;
};