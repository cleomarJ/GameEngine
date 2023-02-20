#pragma once
#include <GL/glew.h>
#include <IWindow.h>
namespace GraphicsDrivers{
    namespace OpenGL{
        class GLWindow: public GraphicsDrivers::Interfaces::IWindow{
            public:
                void create(const GraphicsDrivers::WindowConfig& config);
                void update();
                void close();
        };
    };
}