#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include <raymath.h>
#include <cmath>
#include <vector>

#include "settings.h"
#include "textureHolder.h"
#include "tile.hh"

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
	bool doubleJump;
	PlayerStates state;
    Rectangle rect;
    Rectangle sourceRect;
    std::vector<Tile> scenario;

	/* movement related stuff */
    Vector2 movement{};
    int vel;

    // Draw
    TextureHolder *textureHolder = TextureHolder::getInstance();

    float frame;

    void Move();

public:
    Player();

    ~Player();

    void setPosition(float x , float y);

    void HandleInput();

    void setScenario(std::vector<Tile> s);

    void horizontalCollition();
    
    void verticalCollition();

    void Update();

    void Draw();

    Rectangle getRect();
};
#endif
