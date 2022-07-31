#include "tile.hh"
#include <raylib.h>

Tile::Tile(Rectangle rect, bool isCol, int texture){
    this->rect = rect;
    this->isCol = isCol;
    this->texture = texture;
}

void Tile::draw(){
    /* DrawRectangle(rect.x, rect.y, rect.width, rect.height, BLACK); */
    DrawTexture(textureHolder->getTexture(texture), rect.x, rect.y, WHITE);
}

Rectangle Tile::getRect(){
    return rect;
}

bool Tile::getIsCol(){
    return isCol;
}

