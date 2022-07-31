#include "level.hh"

Level::Level(){
}

void Level::loadLevel(){
    std::ifstream file("resources/maps/level0/level1.csv");

    CSVRow row;
    int i = 0;
    int j = 0;

    while(file >> row)
    {
        for(int j = 0; j < row.size(); j++){
            if(row[j] == "0"){

                Rectangle rect{j * TILESIZE, i * TILESIZE, TILESIZE, TILESIZE};
                Tile tile(rect, false, 1);
                
                tiles.push_back(tile);
            }
            if(row[j] == "1"){

                Rectangle rect{j * TILESIZE, i * TILESIZE, TILESIZE, TILESIZE};
                Tile tile(rect, false, 0);
                
                tiles.push_back(tile);
            }
            if(row[j] == "2"){

                Rectangle rect{j * TILESIZE, i * TILESIZE, TILESIZE, TILESIZE};
                Tile tile(rect, true, 2);
                
                tiles.push_back(tile);
            }
            if(row[j] == "3"){
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
    if(player.isDead()){
        player.setPosition(player.getInit().x, player.getInit().y);
        cameraHolder.resetCamera();
    }else{
        player.Update();
        cameraHolder.update();
    }
}

void Level::draw(){
    for(auto tile : tiles){
        tile.draw();
    }
    player.Draw();
}

Camera2D Level::getCamera(){
    return cameraHolder.getCamera();
}
