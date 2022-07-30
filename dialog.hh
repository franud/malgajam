#include <string>
#include <raylib.h>

class Dialog
{
private:
    std::string text;
    std::string whoIsTalkingText;
    Rectangle whoIsTalkingRectangle;
    Rectangle outter;
    float espacioEntreLineas;

public:
    Dialog(const std::string& whoIsTalking, const std::string& dialogText);
    Dialog();
    ~Dialog();
    void render ();
};
