#include <Gameloop.h>
#include <iostream>
void Engine::Gameloop::start(GraphicsDrivers::Interfaces::IWindow* window){
    using namespace std::chrono_literals;
    using clock = std::chrono::high_resolution_clock;
    using std::chrono::nanoseconds;

    nanoseconds lag(0ns);
    nanoseconds frameLag(0ns);

    auto timeStart = clock::now();

     

    while (running && !window->shouldClose()) {
        auto currentTime = clock::now();
        auto deltaTime = currentTime - timeStart;
        timeStart = currentTime;
        lag += std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime);
            
        while (lag >= timestep){
            Engine::Controller::instance()->process();
            lag -= timestep;
        }

        frameLag += std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime);

        if (frameLag >= frametime) {
                
            frameLag -= frametime;
            auto alpha = (float)lag.count() / timestep.count();
            //render(alpha)
            window->update();
                
        }
    }
}