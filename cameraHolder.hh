#include <raylib.h>
#include "settings.h"

enum class cameraState{
    DEAD, S1, S2, S3, S4, S5
};

class CameraHolder{
private:
    Camera2D camera;
    cameraState state;
    int freezeFrames;

public:
    CameraHolder();

    void update();
    void resetCamera();

    Camera2D getCamera();
};
