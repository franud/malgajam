#include "level.hh"

Level::Level(){
}

void Level::loadLevel(){
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
            if(row[j] == "1"){
                player.setPosition(j * TILESIZE, i * TILESIZE); 
            }
        }
        i++;
    }

    player.setScenario(tiles);
}

void Level::processEvents(){
    player.HandleInput();
}

void Level::update(){
    player.Update();
    camera.offset.x -= 0;
    SetWindowPosition(-camera.offset.x, 0);
}

void Level::draw(){
    for(auto tile : tiles){
        tile.draw();
    }
    player.Draw();
}

Camera2D Level::getCamera(){
    return camera;
}
