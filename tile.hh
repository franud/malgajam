#ifndef TILE_H
#define TILE_H

#include <raylib.h>
#include "textureHolder.h"

class Tile{
private:
    Rectangle rect;
    TextureHolder *textureHolder = TextureHolder::getInstance();

public:
    Tile(Rectangle rect);

    void draw();

    Rectangle getRect();
};

#endif
