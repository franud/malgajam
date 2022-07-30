#include <raylib.h>
#include <raymath.h>

enum class PlayerStates {
	Idle,
    Run,
    JumpStart,
    JumpUp,
    FallDown,
};

class Player{
private:
	bool isGrounded;
	PlayerStates status;
    Rectangle rect;

	/* movement related stuff */
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
