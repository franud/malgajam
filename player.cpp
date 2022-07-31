#include "player.h"
#include "textureHolder.h"
#include <raylib.h>

Player::Player(){
	state = PlayerStates::Idle;	
	isGrounded = false;
    isWalled = false;
	doubleJump = false;
    rect = Rectangle{96, 96, 48, 48};
    sourceRect = Rectangle{0, 0, 48, 48};

	/* movement related stuff */
    movement = Vector2{0, 0};
    vel = 200;

    levelStartPos = Vector2{0,0};

    // Draw
    frame = 0;
    freezeFrames = 10;
}

Player::~Player(){
    /* UnloadTexture(texture); */
}

void Player::setPosition(float x , float y){
    rect.x = x;
    rect.y = y;
    if(isFirst){
        levelStartPos = Vector2{x, y};
        isFirst = false;
        deadCheck = true;
    }
    state = PlayerStates::Idle;
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
    switch(state){
        case PlayerStates::Dead:
        {
        }break;
        default:
        {
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
        break;
    }
}

void Player::Update(){
    switch(state){
        case PlayerStates::Dead:
        {
            if(freezeFrames < 0){
                freezeFrames--;
            }else{
                state = PlayerStates::Idle;
                setPosition(levelStartPos.x, levelStartPos.y);
            }
        }break;
        default:
            Move();  
            if(!isGrounded){
                movement.y += 0.2;
            } else {
                doubleJump = true;
            }
        break;
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
            DrawTextureRec(textureHolder->getTexture(3), Rectangle{sourceRect.x, 96, sourceRect.width, sourceRect.height}, Vector2{rect.x, rect.y}, WHITE);
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

    Vector2 monitorPos = GetWindowPosition();

    if(rect.x + rect.width < monitorPos.x
            || rect.y + rect.height < monitorPos.y
            || rect.x > monitorPos.x + SCREENWIDTH
            || rect.y > monitorPos.y + SCREENHEIGHT){
        if(colberDance){
            colberDance = false;
        }else{
            state = PlayerStates::Dead;
        }
        printf("pum. muerto owo \n");
    }
}

Rectangle Player::getRect(){
    return rect;
}

Vector2 Player::getInit(){
    return levelStartPos;
}

bool Player::isDead(){
    if(deadCheck){
        if(state == PlayerStates::Dead){
            return true;
        }
    }
    return false;
}

