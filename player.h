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
	bool FacingRight;
	float RunSpeed;
	float jumpAcceleration;
	float jumpVelocityDampen;
	int runDir;
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
