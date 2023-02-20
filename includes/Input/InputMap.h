#pragma once
#include <map>
#include <string>
#include <GLFW/glfw3.h>
namespace Input{
    class InputMap{
        public:
            InputMap(InputMap& other) = delete;
            void operator=(const InputMap &) = delete;
            static InputMap* instance();

            std::string& getName(int key);
            int getKey(std::string& name);
        private:
            static InputMap* _inputMap;
            std::string names[1024] = {""};
            std::map<std::string, int> keys;
			void configureKey(std::string name, size_t key);
			InputMap();
    };
};