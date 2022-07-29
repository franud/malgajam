#include "textureHolder.h"
#include <memory>
#include <utility>

void TextureHolder::load(Textures::ID id, const std::string& filename){

    std::unique_ptr<Texture2D> texture (new Texture2D());

    texture->LoadTexture(filename.c_str());

    textureMap.insert(std::make_pair(id, std::move(texture)));
}
