#include <raylib.h>
#include <raymath.h>

class Player{
    private:
    Rectangle rect;
    Vector2 movement{};
    int vel;

    Texture2D texture;

    void Move();

    public:
    Player();

    ~Player();

    void HandleInput();

    void Update();

    void Draw();
};
