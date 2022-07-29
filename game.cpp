#include "game.h"

Game::Game(){
    InitWindow(SCREENWIDTH, SCREENWIDTH, "Zelda Like");
    SetTargetFPS(FPS);
}

Game::~Game(){
    CloseWindow();
}

void Game::Run(){
    while(!WindowShouldClose()){
        ProcessEvents();
        Update();
        Render();
    }
}

void Game::ProcessEvents(){
    player.HandleInput();
}

void Game::Update(){
    player.Update();
}

void Game::Render(){
BeginDrawing();
    ClearBackground(BLACK);
    player.Draw();
EndDrawing();
}
