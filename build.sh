g++ -g -o /home/cleomar/Projetos/GameEngine/build/teste \
/home/cleomar/Projetos/GameEngine/main.cpp \
/home/cleomar/Projetos/GameEngine/src/Engine/*.cpp \
/home/cleomar/Projetos/GameEngine/src/Input/*.cpp \
/home/cleomar/Projetos/GameEngine/src/GraphicsDrivers/*.cpp \
/home/cleomar/Projetos/GameEngine/src/GraphicsDrivers/OpenGL/*.cpp \
/home/cleomar/Projetos/GameEngine/src/Scenes/*.cpp \
-I /home/cleomar/Projetos/GameEngine/includes/Engine \
-I /home/cleomar/Projetos/GameEngine/includes/Input \
-I /home/cleomar/Projetos/GameEngine/includes/GraphicsDrivers \
-I /home/cleomar/Projetos/GameEngine/includes/GraphicsDrivers/OpenGL \
-I /home/cleomar/Projetos/GameEngine/includes/GraphicsDrivers/Interfaces \
-I /home/cleomar/Projetos/GameEngine/includes/Scenes \
-I /home/cleomar/Projetos/GameEngine/external_libs \
-lGLEW -lglfw -lOpenGL
