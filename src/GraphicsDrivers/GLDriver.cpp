#include <GLDriver.h>

GraphicsDrivers::GLDriver* GraphicsDrivers::GLDriver::glDriver_ = nullptr;

GraphicsDrivers::GLDriver::GLDriver(){
    GraphicsDrivers::WindowConfig config;
    
    window_ = new GraphicsDrivers::OpenGL::GLWindow();
    window_->create(config);
   
}

GraphicsDrivers::GLDriver* GraphicsDrivers::GLDriver::instance(){
    if(glDriver_ != nullptr){
        return nullptr;
    }
    return glDriver_;
}
GraphicsDrivers::GLDriver* GraphicsDrivers::GLDriver::create(GraphicsDrivers::Driver driver){
    glDriver_ = new GraphicsDrivers::GLDriver();
    return glDriver_;
}

GraphicsDrivers::Interfaces::IWindow* GraphicsDrivers::GLDriver::getWindow(){
    return window_;
}
GraphicsDrivers::Interfaces::IWindow* GraphicsDrivers::GLDriver::window(){
    return glDriver_->getWindow();
}