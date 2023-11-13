#include "texture.h"

#include "canvas.h"
#include "texture_loader.h"

Texture2D::Texture2D(const std::string &filePath)
{
    this->filePath = filePath;
    auto &canvas = Canvas::GetInstance();
    texture = IMG_LoadTexture(canvas.GetRenderer(), filePath.c_str());
    SDL_Log("Texture2D Created!");
}

Texture2D::~Texture2D()
{
    TextureLoader::GetInstance().Unload(this->filePath);
    SDL_DestroyTexture(texture);
    texture = nullptr;

    SDL_Log("Texture2D Destroyed!");
}
