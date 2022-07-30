#include <raylib.h>
#include <raymath.h>

#include "settings.h"
#include "level.hh"
#include "textureHolder.h"

class Game{
    private:
    Level level;

    void ProcessEvents();
    void Update();
    void Render();

    public:
    Game();

    ~Game();

    void Run();
};


