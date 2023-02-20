#include <InputCallback.h>
Input::InputCallback* Input::InputCallback::inputCallback_ = nullptr;

void Input::InputCallback::keyInput(int key, bool release){

}
void Input::InputCallback::mouseMovement(double xPos, double yPos){

}

Input::InputCallback* Input::InputCallback::instance(){
    if(inputCallback_ == nullptr){
        inputCallback_ = new InputCallback();
    }
    return inputCallback_;
}