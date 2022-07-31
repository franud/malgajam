#include "cameraHolder.hh"
#include <cstdio>
CameraHolder::CameraHolder(){
    camera = Camera2D{Vector2{0,0}, Vector2{0,0}, 0, 1.0f};
    state = cameraState::S1;
    freezeFrames = 60;
}

void CameraHolder::resetCamera(){
    /* state = cameraState::DEAD; */
    camera.offset = Vector2{0,0};
    state = cameraState::S1;
    freezeFrames = 60;
}

void CameraHolder::update(){
    switch(state){
        case cameraState::S1:
        {
            //Pausa el estado
            if(freezeFrames > 0){
                freezeFrames--;
            }else{
                //Movimiento a la derecha hasta el borde de la pantalla
                if(-camera.offset.x + SCREENWIDTH < MONITORWIDTH){
                    camera.offset.x -= 3;
                }else{
                    state = cameraState::S2;
                    freezeFrames = 60;
                }
            }
        }break;
        case cameraState::S2:
        {
            //Pausa el estado
            if(freezeFrames > 0){
                freezeFrames--;
            }else{
                //Movimiento hacia abajo hasta el borde de la pantalla
                if(-camera.offset.y + SCREENHEIGHT < TILESIZE * 19){
                    camera.offset.y -= 2;
                }else{
                    state = cameraState::S3;
                    freezeFrames = 60;
                }
            }
        }break;
        case cameraState::S3:
        {
            //Pausa el estado
            if(freezeFrames > 0){
                freezeFrames--;
            }else{
                //Movimiento hacia la izquierda hasta el borde de la pantalla
                if(-camera.offset.x > 0){
                    camera.offset.x += 3;
                }else{
                    state = cameraState::S4;
                    freezeFrames = 60;
                }
            }
        }break;
        case cameraState::S4:
        {
            //Pausa el estado
            if(freezeFrames > 0){
                freezeFrames--;
            }else{
                //Movimiento hacia abajo hasta el borde de la pantalla
                if(-camera.offset.y < MONITORHEIGHT - SCREENHEIGHT){
                    camera.offset.y -= 2;
                }else{
                    state = cameraState::S5;
                    freezeFrames = 60;
                }
            }
        }break;
        case cameraState::S5:
        {
            //Pausa el estado
            if(freezeFrames > 0){
                freezeFrames--;
            }else{
                //Movimiento hacia abajo hasta el borde de la pantalla
                if(-camera.offset.y < MONITORHEIGHT - SCREENHEIGHT){
                    camera.offset.y -= 2;
                }else{
                    state = cameraState::S1;
                    freezeFrames = 60;
                }
            }
        }break;
        default:
        break;
    }
    SetWindowPosition(-camera.offset.x, -camera.offset.y);
}

Camera2D CameraHolder::getCamera(){
    return camera;
}
