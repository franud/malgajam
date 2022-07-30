#include "player.h"
#include "settings.h"
#include <ostream>
#include <raylib.h>
#include <raymath.h>

Player::Player(){
	status = PlayerStates::Idle;	
	isGrounded = false;
    rect = Rectangle{1, 1, 16, 16};

	/* movement related stuff */
    movement = Vector2{0, 0};
    vel = 200;
    /* texture = LoadTexture("resources/player.png"); */
}

Player::~Player(){
    /* UnloadTexture(texture); */
}

void Player::HandleInput(){
	if (IsKeyPressed(KEY_UP)) {
		if (isGrounded) {
			movement.y = -3;
			isGrounded = false;
		}
	}

    if(IsKeyPressed(KEY_RIGHT)){
        movement.x += 1;
	}else if (IsKeyReleased(KEY_RIGHT)){
        movement.x -= 1;
    }
    if(IsKeyPressed(KEY_LEFT)){
        movement.x -= 1;
    }else if (IsKeyReleased(KEY_LEFT)){
        movement.x += 1;
    }
}

void Player::Update(){
    Move();
}

void Player::Draw(){
    DrawRectangleRec(rect, WHITE);
}

void Player::Move(){
	rect.x += movement.x * vel * GetFrameTime();
    rect.y += movement.y * vel * GetFrameTime();

	if (rect.y + rect.height > SCREENHEIGHT) {
		isGrounded = true;
		rect.y = SCREENHEIGHT - rect.height;
	}
	if (!isGrounded) {
		movement.y += 0.2;
	}
}
