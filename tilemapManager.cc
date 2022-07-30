#include <raylib.h>
#include <vector>
#include <stdio.h>

#include "settings.h"
#include "csvParser.cc"
#include "tile.hh"

class Level{
private:
    std::vector<Tile> tiles;

public:
    Level();

    void LoadLevel();

    void draw();
};

Level::Level(){
}

void Level::LoadLevel(){
    std::ifstream file("tilemap.csv");

    CSVRow row;
    int i = 0;
    int j = 0;

    while(file >> row)
    {
        for(int j = 0; j < row.size(); j++){
            if(row[j] == "0"){

                Rectangle rect{j * TILESIZE, i * TILESIZE, TILESIZE, TILESIZE};
                Tile tile(rect);
                
                tiles.push_back(tile);
            }
        }
        i++;
    }
}

void Level::draw(){
    for(auto tile : tiles){
        tile.draw();
    }
}

int main(){
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Tilemap Manager");
    SetTargetFPS(FPS);

    Level level;
    level.LoadLevel();

    while(!WindowShouldClose()){
    
    BeginDrawing();
        ClearBackground(BLACK);
        level.draw();
    EndDrawing();
    }

    CloseWindow();
    return 0;
}
