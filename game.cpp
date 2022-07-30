#include "game.hh"

Game::Game() {
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Zelda Like");
    SetTargetFPS(FPS);
    this->dialog = Dialog("Gabi", "Hola que tal :D\nPrueba de salto de linea");
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
    this->dialog.render();
    EndDrawing();
}
