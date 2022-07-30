#include "dialog.hh"

Dialog::Dialog()
{

}

Dialog::Dialog(const std::string& whoIsTalking, const std::string& dialogText)
{
    this->text = dialogText;
    this->whoIsTalkingText = whoIsTalking;
    this->outter = {
        .x = 2.0f * ((float) GetScreenWidth()) / 64.0f,
        .y = 2.0f * ((float) GetScreenHeight()) / 3.0f,
        .width = 60.0f * ((float) GetScreenWidth()) / 64.0f,
        .height = 1.0f * ((float) GetScreenHeight()) / 3.0f - (float) GetScreenHeight() / 32.0f
    };
    this->whoIsTalkingRectangle = {
        .x = 2.0f * ((float) GetScreenWidth()) / 64.0f,
        .y = 2.0f * ((float) GetScreenHeight()) / 3.0f - (6.0f * ((float) GetScreenWidth()) / 64.0f),
        .width = 33.0f * ((float) GetScreenWidth()) / 100.0f,
        .height = 4.5f * ((float) GetScreenHeight()) / 32.0f
    };
}

Dialog::~Dialog()
{
}

void Dialog::render () {
    DrawRectangleRec (this->whoIsTalkingRectangle, GREEN);
    DrawRectangleRec (this->outter, WHITE);
    float inicioTextoX = 4.0f * (float) GetScreenWidth() / 64.0f ;
    float inicioTextoY = 17.0f * ((float) GetScreenHeight()) / 24.0f;
    int fuenteTexto = (GetScreenHeight() * 45) / 1080;
    DrawText(this->text.c_str(), inicioTextoX, inicioTextoY, fuenteTexto, BLACK);
    float inicioWhoX = 6.0f * ((float) GetScreenWidth()) / 100.0;
    float inicioWhoY = 60.0f * ((float) GetScreenHeight()) / 100.0f;
    int fuenteTextoWho = (GetScreenWidth() * 40) / 1080;
    DrawText(this->whoIsTalkingText.c_str(), inicioWhoX, inicioWhoY, fuenteTextoWho, RED);
}