#pragma once
#include <string>

namespace Input{
    class Input{
        public:
            Input(std::string, int,bool);
            std::string& getName();
            int getKey();
            bool isPressed();
            bool isReleased();
            
        private:
            std::string name;
            int key;
            bool pressed;
    };
}