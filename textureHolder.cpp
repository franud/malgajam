#include "textureHolder.h"

// Define the static TextureHolder pointer
TextureHolder* TextureHolder::inst_ = NULL;

TextureHolder* TextureHolder::getInstance() {
   if (inst_ == NULL) {
      inst_ = new TextureHolder();
   }
   return(inst_);
}

void TextureHolder::addTexture(int id, const std::string& path) {
    Image image = LoadImage(path.c_str());
    Texture2D texture = LoadTextureFromImage(image);
    idToTexture.insert(std::make_pair(id, texture));
    UnloadImage(image);
}

Texture2D TextureHolder::getTexture (int id) {
    return idToTexture[id];
}

void TextureHolder::loadTextures(){
    addTexture(0, "resources/sprites/tiles/bkg0.png");
    addTexture(1, "resources/sprites/tiles/bkg1.png");
    addTexture(2, "resources/sprites/tiles/block.png");
    addTexture(3, "resources/sprites/player/anim.png");
}
