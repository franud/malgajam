#include <raylib.h>
#include "settings.hh"
#include "player.hh"
#include "dialog.hh"

class Game{
    private:
    Player player;
    Dialog dialog;

    void ProcessEvents();
    void Update();
    void Render();

    public:
    Game();

    ~Game();

    void Run();
};


