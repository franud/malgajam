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
    idToTexture.insert(std::make_pair(id, &texture));
    UnloadImage(image);
}

Texture2D* TextureHolder::getTexture (int id) {
    if (this->idToTexture.find(id) == idToTexture.end()) {
        printf ("ESA TEXTURA CON ID %i NO EXISTE\n", id);
        exit(999);
    }
    return this->idToTexture[id];
}