#include <InputCallback.h>
#include <iostream>
Input::InputCallback* Input::InputCallback::inputCallback_ = nullptr;

Input::InputCallback::InputCallback(){

};
void Input::InputCallback::keyInput(int key, bool pressed){
    InputControl::instance()->getKeys()[key] = pressed;
    Input input = Input(InputMap::instance()->getName(key),key,pressed);
    Engine::Controller::instance()->input(input);
}
void Input::InputCallback::mouseMovement(double xPos, double yPos){

}

Input::InputCallback* Input::InputCallback::instance(){
    if(inputCallback_ == nullptr){
        inputCallback_ = new InputCallback();
    }
    return inputCallback_;
}