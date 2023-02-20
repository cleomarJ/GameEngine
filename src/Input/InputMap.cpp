#include <InputMap.h>
Input::InputMap* Input::InputMap::_inputMap = nullptr;
Input::InputMap::InputMap(){
    configureKey("exit", GLFW_KEY_ESCAPE);
    configureKey("jump", GLFW_KEY_W);
};
Input::InputMap* Input::InputMap::instance(){
    if(_inputMap == nullptr){
        _inputMap = new Input::InputMap();
    }
    return _inputMap;
}
std::string& Input::InputMap::getName(int key){
    return names[key];
}

void Input::InputMap::configureKey(std::string name, size_t key){
    names[key] = name;
    keys[name] = key;
}

int Input::InputMap::getKey(std::string& name){
    return keys[name];
}