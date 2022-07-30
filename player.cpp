#include "player.h"
#include "textureHolder.h"

Player::Player(){
	state = PlayerStates::Idle;	
	isGrounded = false;
    rect = Rectangle{0, 0, 128, 128};
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

void Player::HandleInput(){
	if (IsKeyPressed(KEY_UP)) {
		if (isGrounded) {
			movement.y = -3;
			isGrounded = false;
		}
	}

    if(IsKeyPressed(KEY_RIGHT)){
        frame = 0;
        movement.x += 1;
	}else if (IsKeyReleased(KEY_RIGHT)){
        movement.x -= 1;
    }
    if(IsKeyPressed(KEY_LEFT)){
        frame = 0;
        movement.x -= 1;
    }else if (IsKeyReleased(KEY_LEFT)){
        movement.x += 1;
    }

    if(movement.x != 0){
        state = PlayerStates::Run;
    }else{
        state = PlayerStates::Idle;
    }
}

void Player::Update(){
    Move();
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
            DrawTextureRec(textureHolder->getTexture(0), Rectangle{sourceRect.x, 0, sourceRect.width, sourceRect.height}, Vector2{rect.x, rect.y}, WHITE);
        }break;
        case PlayerStates::Run:
        {
            frame += 0.1f;
            if(frame > 2){
                frame = 0;
            }
            DrawTextureRec(textureHolder->getTexture(0), Rectangle{sourceRect.x, 128, sourceRect.width, sourceRect.height}, Vector2{rect.x, rect.y}, WHITE);
        }break;
        default:
        break;
    }
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
