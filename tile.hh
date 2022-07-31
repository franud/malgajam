#ifndef TILE_H
#define TILE_H

#include <raylib.h>
#include "textureHolder.h"

class Tile{
private:
    Rectangle rect;
    TextureHolder *textureHolder = TextureHolder::getInstance();
    bool isCol;
    int texture;

public:
    Tile(Rectangle rect, bool isCol, int texture);

    void draw();

    Rectangle getRect();

    bool getIsCol();
};

#endif
