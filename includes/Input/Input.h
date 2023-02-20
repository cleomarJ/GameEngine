#pragma once
#include <string>

namespace Input{
    class Input{
        public:
            Input(std::string, size_t,bool);
            std::string& getName();
            size_t getKey();
            bool isPressed();
            bool isReleased();
            
        private:
            std::string name;
            size_t key;
            bool pressed;
    };
}