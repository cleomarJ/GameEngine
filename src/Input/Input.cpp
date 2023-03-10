#include <Input.h>


Input::Input::Input(std::string name, int key,bool pressed){
    this->name = name;
    this->key = key;
    this->pressed = pressed;
}
std::string& Input::Input::getName(){
    return name;
}
int Input::Input::getKey(){
    return key;
}
bool Input::Input::isPressed(){
    return pressed;
}
bool Input::Input::isReleased(){
    return !pressed;
}