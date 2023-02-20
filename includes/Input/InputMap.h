#pragma once
#include <map>
#include <string>
namespace Input{
    class InputMap{
        public:
            InputMap(InputMap& other) = delete;
            void operator=(const InputMap &) = delete;
            static InputMap* instance();

            std::string& getName(const size_t key);
            size_t getKey(std::string& name);
        private:
            static InputMap* _inputMap;
            std::string names[1024] = {""};
            std::map<std::string, size_t> keys;
			void configureKey(std::string name, size_t key);
			InputMap();
    };
};