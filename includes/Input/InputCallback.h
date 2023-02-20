#pragma once
#include <Controller.h>
#include <InputMap.h>
#include <InputControl.h>
#include <Input.h>


namespace Input{
    class InputCallback{
        public:
            InputCallback(InputCallback& other) = delete;
			void operator=(const InputCallback&) = delete;
            
            void keyInput(int key, bool release);
			void mouseMovement(double xPos, double yPos);
            static InputCallback* instance();
        private:
            InputCallback();
            static InputCallback* inputCallback_;
    };
};