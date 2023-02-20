#pragma once
#include <string>
#include <InputMap.h>

namespace Input{
    class InputControl{
        public:
            InputControl(InputControl& other) = delete;
            void operator=(const InputControl &) = delete;
            static InputControl* instance();

            bool isKeyPressed(std::string& name);
			bool* getKeys();

        private:
            static InputControl* inputControl_;
            bool keys[1024]{false};
            InputControl();
    };
};