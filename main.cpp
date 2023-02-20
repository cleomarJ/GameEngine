#include <GLDriver.h>
#include <MainScene.h>
#include <Gameloop.h>
#include <iostream>
int main(){
    GraphicsDrivers::GLDriver::create(GraphicsDrivers::Driver::OPENGL);
    new Scenes::MainScene();
    auto loop = new Engine::Gameloop();
    loop->start(GraphicsDrivers::GLDriver::window());
}