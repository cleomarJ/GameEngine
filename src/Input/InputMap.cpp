#include <InputMap.h>
Input::InputMap* Input::InputMap::_inputMap = nullptr;

Input::InputMap* Input::InputMap::instance(){
    if(_inputMap == nullptr){
        _inputMap = new Input::InputMap();
    }
    return _inputMap;
}
std::string& Input::InputMap::getName(const size_t key){
    return names[key];
}

void Input::InputMap::configureKey(std::string name, size_t key){
    names[key] = name;
    keys[name] = key;
}

size_t Input::InputMap::getKey(std::string& name){
    return keys[name];
}