#include "player.h"
#include "settings.h"
#include <ostream>
#include <raylib.h>
#include <raymath.h>

Player::Player(){
	isGrounded = false;
    rect = Rectangle{1, 1, 16, 16};
    movement = Vector2{0, 0};
    vel = 200;
    /* texture = LoadTexture("resources/player.png"); */
}

Player::~Player(){
    /* UnloadTexture(texture); */
}

void Player::HandleInput(){
    if(IsKeyPressed(KEY_UP)){
        movement.y -= 1;
    }else if (IsKeyReleased(KEY_UP)){
        movement.y += 1;
    }
    if(IsKeyPressed(KEY_RIGHT)){
        movement.x += 1;
	}else if (IsKeyReleased(KEY_RIGHT)){
        movement.x -= 1;
    }
    if(IsKeyPressed(KEY_DOWN)){
        movement.y += 1;
    }else if (IsKeyReleased(KEY_DOWN)){
        movement.y -= 1;
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
	isGrounded = (rect.y + rect.height == SCREENHEIGHT);
	rect.x += movement.x * vel * GetFrameTime();
    rect.y += movement.y * vel * GetFrameTime();

	if (rect.x < 0) {
		rect.x = 0;
	}
	if (rect.x + rect.width > SCREENWIDTH) {
		rect.x = SCREENWIDTH - rect.width;
	}
	if (rect.y < 0) {
		rect.y = 0;
	}
	if (rect.y + rect.height > SCREENHEIGHT) {
		rect.y = SCREENHEIGHT - rect.height;
	}
	if (!isGrounded) {
		rect.y += 1;
	}
}
