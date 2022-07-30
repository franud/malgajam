#include "game.h"

Game::Game(){
}

Game::~Game(){
    CloseWindow();
}

void Game::Run(){
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Zelda Like");

    SetTargetFPS(FPS);
    
    TextureHolder *textureHolder = TextureHolder::getInstance();
    textureHolder->loadTextures();

    level.loadLevel();

    while(!WindowShouldClose()){
        ProcessEvents();
        Update();
        Render();
    }
}

void Game::ProcessEvents(){
    level.processEvents();
}

void Game::Update(){
    level.update();
}

void Game::Render(){
    BeginDrawing();
	ClearBackground(WHITE);
    level.draw();
    EndDrawing();
}
