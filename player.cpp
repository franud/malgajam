#include "player.h"
#include "textureHolder.h"
#include <raylib.h>

Player::Player(){
	state = PlayerStates::Idle;	
	isGrounded = false;
    isWalled = false;
	doubleJump = false;
    rect = Rectangle{0, 0, 96, 96};
    sourceRect = Rectangle{0, 0, rect.width, rect.height};

	/* movement related stuff */
    movement = Vector2{0, 0};
    vel = 200;

    // Draw
    frame = 0;
}

Player::~Player(){
    /* UnloadTexture(texture); */
}

void Player::setPosition(float x , float y){
    rect.x = x;
    rect.y = y;
}

void Player::setScenario(std::vector<Tile> s){
    scenario = s;
}

void Player::horizontalCollition () {
	for (Tile t : scenario) {
        if(t.getIsCol()){
            if (CheckCollisionRecs(rect, t.getRect())) {
                if (movement.x < 0) {
                    rect.x = t.getRect().x + t.getRect().width;
                }		
                if (movement.x > 0) {
                    rect.x = t.getRect().x - rect.width;
                }
            }
        }
	}
}

void Player::verticalCollition () {
	for (Tile t : scenario) {
        if(t.getIsCol()){
            if (CheckCollisionRecs(this->rect, t.getRect())) {
                if (movement.y < 0) {
                    movement.y = 0;
                    rect.y = t.getRect().y + t.getRect().height;
                }
                if (movement.y > 0) {
                    isGrounded = true; // is grounded in top of the tile
                    rect.y = t.getRect().y - this->rect.height;
                }
            }
        }
	}
}

void Player::HandleInput(){
	if (IsKeyPressed(KEY_UP)) {
		if (isGrounded) {
			movement.y = -3;
			isGrounded = false;
            isWalled = false;
        } else if (doubleJump) {
			movement.y = -3;
			doubleJump = false;
            isWalled = false;
        } else if (isWalled) {
            movement.y = -3;
            isWalled = false;
        }
	}

    if(IsKeyPressed(KEY_RIGHT)){
        movement.x += 1;
	} else if (IsKeyReleased(KEY_RIGHT)){
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
    if(!isGrounded){
        movement.y += 0.2;
    } else {
		doubleJump = true;
	}
}

void Player::Draw(){
    
    sourceRect.x = rect.width * int(frame);
    if(movement.x < 0){
        sourceRect.width = -(std::abs(sourceRect.width));
    }else if(movement.x > 0){
        sourceRect.width = std::abs(sourceRect.width);
    }

    switch(state)
    {
        case PlayerStates::Idle:
        {
            frame += 0.125f;
            if(frame > 3){
                frame = 0;
            }
            DrawTextureRec(textureHolder->getTexture(3), Rectangle{sourceRect.x, 0, sourceRect.width, sourceRect.height}, Vector2{rect.x, rect.y}, WHITE);
        }break;
        case PlayerStates::Run:
        {
            frame += 0.1f;
            if(frame > 2){
                frame = 0;
            }
            DrawTextureRec(textureHolder->getTexture(3), Rectangle{sourceRect.x, 128, sourceRect.width, sourceRect.height}, Vector2{rect.x, rect.y}, WHITE);
        }break;
        default:
        break;
    }
}

void Player::Move(){
    isGrounded=false;
	rect.x += movement.x * vel * GetFrameTime();
	horizontalCollition();
    rect.y += movement.y * vel * GetFrameTime();
	verticalCollition();

	/* if (rect.y + rect.height >= SCREENHEIGHT) { */
	/* 	isGrounded = true; */
	/* } */

    if(rect.y+rect.height >= TILESIZE * 10 
            || rect.y < 0
            || rect.x < 0
            || rect.x + rect.width >= TILESIZE * 10){
        /* printf("pum. muerto owo \n"); */
    }
}

Rectangle Player::getRect(){
    return rect;
}
