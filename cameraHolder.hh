#include <raylib.h>
#include "settings.h"

enum class cameraState{
    S1, S2, S3, S4
};

class CameraHolder{
private:
    Camera2D camera;
    cameraState state;
    int freezeFrames;

public:
    CameraHolder();
    void update();
    Camera2D getCamera();
};
