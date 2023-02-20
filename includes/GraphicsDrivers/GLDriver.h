#pragma once
#include <GLWindow.h>

namespace GraphicsDrivers{
    enum class Driver{
        VULKAN,
        OPENGL
    };
    class GLDriver{
        private:
            GLDriver();
            static GLDriver* glDriver_;
            GraphicsDrivers::Interfaces::IWindow* window_;
            
        public:
            GLDriver(GLDriver& other) = delete;
            void operator=(const GLDriver &) = delete;
            static GLDriver* instance();
            static GLDriver* create(Driver);
            static GraphicsDrivers::Interfaces::IWindow* window();
            GraphicsDrivers::Interfaces::IWindow* getWindow();
    };
};