#include <raylib.h>
#include "settings.h"
#include "player.h"

class Game{
    private:
    Player player;

    void ProcessEvents();
    void Update();
    void Render();

    public:
    Game();

    ~Game();

    void Run();
};

int main(){
    Game game;
    game.Run();
}
