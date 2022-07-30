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
        .width = 3.0f * ((float) GetScreenWidth()) / 8.0f,
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
    float inicioTextoY = 2.0f * ((float) GetScreenHeight()) / 3.0f + (1.0f * ((float) GetScreenHeight()) / 64.0f);
    DrawText(this->text.c_str(), inicioTextoX, inicioTextoY, 15, WHITE);
}