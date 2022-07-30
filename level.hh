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

public:
    Level();

    void loadLevel();

    void processEvents();

    void update();

    void draw();
};
