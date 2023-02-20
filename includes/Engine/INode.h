#pragma once
#include <Input.h>

namespace Engine{
    class INode{
        public:
            virtual void process() {};
            virtual void input(Input::Input& input) {};
            virtual void cursor(double xPos, double yPos) {};

            void setActive(bool active) { this->active = active; };
		    bool isActive() { return active; };
        protected:
		    bool active = true;
    };
};