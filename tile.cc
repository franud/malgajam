#include "tile.hh"
#include <raylib.h>

Tile::Tile(Rectangle rect){
    this->rect = rect;
}

void Tile::draw(){
    /* DrawRectangle(rect.x, rect.y, rect.width, rect.height, BLACK); */
    DrawTexture(textureHolder->getTexture(2), rect.x, rect.y, WHITE);
}

Rectangle Tile::getRect(){
    return rect;
}

