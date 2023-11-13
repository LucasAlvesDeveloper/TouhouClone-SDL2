#include "texture_loader.h"

#include "timer.h"

TextureLoader::TextureLoader()
{
}

TextureLoader::~TextureLoader()
{
    loadedTextures.clear();
}

Texture2D TextureLoader::GetTexture(const std::string &filePath)
{
    if (loadedTextures.find(filePath) == loadedTextures.end())
    {
        loadedTextures[filePath] = std::make_unique<CacheTexture>(filePath);
    }
    else
    {
        loadedTextures[filePath]->count += 1;
    }

    return loadedTextures[filePath]->texture;
}

void TextureLoader::Unload(const std::string &filePath)
{
    if (loadedTextures.find(filePath) != loadedTextures.end())
    {
        auto &cache = loadedTextures[filePath];

        if (cache->count > 0)
            cache->count -= 1;
    }
}

void TextureLoader::Update(const float secondsToDeleteTexture)
{
    for (auto it = loadedTextures.begin(); it != loadedTextures.end();)
    {
        auto &cacheTexture = it->second;

        if (cacheTexture->count > 0)
        {
            if (cacheTexture->loadedTime > 0.0f)
                cacheTexture->loadedTime = 0.0f;

            ++it;
        }
        else
        {
            cacheTexture->loadedTime += Timer::GetDeltaTime();

            if (cacheTexture->loadedTime >= secondsToDeleteTexture)
            {
                it = loadedTextures.erase(it);
            }
            else
                ++it;
        }
    }
}

TextureLoader &TextureLoader::GetInstance()
{
    static TextureLoader instance;

    return instance;
}