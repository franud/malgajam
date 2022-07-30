#include "dialog.hh"

Dialog::Dialog()
{

}

Dialog::Dialog(const std::string& whoIsTalking, const std::string& dialogText)
{
    this->text = dialogText;
    this->whoIsTalkingText = whoIsTalking;
    this->outter = {
        .x = 3.0f * ((float) GetScreenWidth()) / 100.0f,
        .y = 60.0f * ((float) GetScreenHeight()) / 100.0f,
        .width = 94.0f * ((float) GetScreenWidth()) / 100.0f,
        .height = 37.0f * ((float) GetScreenHeight()) / 100.0f
    };
    this->whoIsTalkingRectangle = {
        .x = 3.0f * ((float) GetScreenWidth()) / 100.0f,
        .y = 47.5f * ((float) GetScreenHeight()) / 100.0f,
        .width = 33.0f * ((float) GetScreenWidth()) / 100.0f,
        .height = 10.0f * ((float) GetScreenHeight()) / 100.0f
    };
}

Dialog::~Dialog()
{
}

void Dialog::render () {
    DrawRectangleRec (this->whoIsTalkingRectangle, GREEN);
    DrawRectangleRec (this->outter, WHITE);
    float inicioTextoX = 4.0f * ((float) GetScreenWidth()) / 100.0f ;
    float inicioTextoY = 61.0f * ((float) GetScreenHeight()) / 100.0f;
    int fuenteTexto = (GetScreenWidth() * 35) / 1080;
    DrawText(this->text.c_str(), inicioTextoX, inicioTextoY, fuenteTexto, BLACK);
    float inicioWhoX = 4.0f * ((float) GetScreenWidth()) / 100.0;
    float inicioWhoY = 50.0f * ((float) GetScreenHeight()) / 100.0f;
    int fuenteTextoWho = (GetScreenWidth() * 35) / 1080;
    DrawText(this->whoIsTalkingText.c_str(), inicioWhoX, inicioWhoY, fuenteTextoWho, RED);
}