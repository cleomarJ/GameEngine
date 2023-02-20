#include <InputControl.h>
Input::InputControl* Input::InputControl::inputControl_ = nullptr;

Input::InputControl* Input::InputControl::instance(){
    if(inputControl_ == nullptr){
        inputControl_ = new InputControl();
    }
    return inputControl_;
}

bool Input::InputControl::isKeyPressed(std::string& name){
    return keys[Input::InputMap::instance()->getKey(name)];
}

bool* Input::InputControl::getKeys(){
    return keys;
}
