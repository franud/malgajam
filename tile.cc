#include "tile.hh"

Tile::Tile(Rectangle rect){
    this->rect = rect;
}

void Tile::draw(){
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, BLACK);
}

