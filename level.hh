#include <raylib.h>
#include <vector>
#include <stdio.h>

#include "settings.h"
#include "tile.hh"
#include "csvParser.hh"
#include "player.h"

class Level{
private:
    std::vector<Tile> tiles;
    Player player;
    Camera2D camera{Vector2{0,0}, Vector2{0,0}, 0, 1.0f};

public:
    Level();

    void loadLevel();

    void processEvents();

    void update();

    void draw();

    Camera2D getCamera();
};
