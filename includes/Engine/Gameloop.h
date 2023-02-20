#pragma once
#include <chrono>
#include <IWindow.h>

namespace Engine{
    class Gameloop{
        private:
            const std::chrono::nanoseconds timestep = std::chrono::nanoseconds(16666666);
            const std::chrono::nanoseconds frametime = std::chrono::nanoseconds(16666666);
            bool running = true;
        public:
            void start(GraphicsDrivers::Interfaces::IWindow* window);
    };
};