#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include <InputCallback.h>
namespace GraphicsDrivers{
    struct WindowConfig {
        std::string name = "window";

        unsigned int width = 1280;
        unsigned int height = 720;

        bool fullscreen = false;
        bool vsync = false;

        int samples = 0;
    };
    namespace Interfaces{
        
        class IWindow{
            protected:
                GLFWwindow* glfwWindow = nullptr;
                int width = 0;
                int height = 0;
                static void keyInput(GLFWwindow* window, int key, int code, int action, int mode){
                    if(action == GLFW_PRESS){
                        Input::InputCallback::instance()->keyInput(key,true);
                    }
                    if(action == GLFW_RELEASE){
                        Input::InputCallback::instance()->keyInput(key,false);
                    }
                }
                static void mouseMovement(GLFWwindow* window, double xPos, double yPos){};
                
            public:
                GLFWwindow* getGlfwWindow(){return glfwWindow;};
                virtual void create(const GraphicsDrivers::WindowConfig& config){};
                int getWidth(){return width;};
                int getHeight(){return height;};
                virtual void update(){};
                virtual void close(){
                    glfwSetWindowShouldClose(glfwWindow, GL_TRUE);
                    glfwDestroyWindow(glfwWindow);
	                glfwTerminate();};
                virtual bool shouldClose(){return glfwWindowShouldClose(glfwWindow);};
        };
    };
};