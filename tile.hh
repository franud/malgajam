#include <raylib.h>

class Tile{
private:
    Rectangle rect;
    Texture2D texture;

public:
    Tile(Rectangle rect);

    void draw();
};
