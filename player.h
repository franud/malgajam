#include <raylib.h>
#include <raymath.h>
#include <cmath>

#include "settings.h"
#include "textureHolder.h"

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
	PlayerStates state;
    Rectangle rect;
    Rectangle sourceRect;

	/* movement related stuff */
    Vector2 movement{};
    int vel;

    // Draw

    Texture2D texture;
    float frame;

    void Move();

public:
    Player();

    void LoadText();

    ~Player();

    void HandleInput();

    void Update();

    void Draw();
};
