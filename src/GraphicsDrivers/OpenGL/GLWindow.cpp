#include <GLWindow.h>
void GraphicsDrivers::OpenGL::GLWindow::create(const GraphicsDrivers::WindowConfig& config){
    if (!glfwInit())
	{
		printf("Error Initialising GLFW");
		glfwTerminate();
        return;
	}
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    if(config.samples > 0){
        glfwWindowHint(GLFW_SAMPLES, config.samples);
    }

	glfwWindow = glfwCreateWindow(config.width, config.height, config.name.c_str(), NULL, NULL);

    if (!glfwWindow)
	{
		printf("Error creating GLFW window!");
		glfwTerminate();
		return;
	}

    glfwGetFramebufferSize(glfwWindow, &this->width, &this->height);
	glfwMakeContextCurrent(glfwWindow);
	glfwSwapInterval( 0 );
	 
	glfwSetKeyCallback(this->glfwWindow, this->keyInput);
	glfwSetCursorPosCallback(this->glfwWindow, this->mouseMovement);
    glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glewExperimental = GL_TRUE;
	
    GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		printf("Error: %s", glewGetErrorString(error));
		glfwDestroyWindow(glfwWindow);
		glfwTerminate();
		return;
	}
	
    glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, this->width, this->height);
	
}
void GraphicsDrivers::OpenGL::GLWindow::update(){
    glfwSwapBuffers(glfwWindow);
	glfwPollEvents();
	glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void GraphicsDrivers::OpenGL::GLWindow::close(){
    glfwSetWindowShouldClose(glfwWindow, GL_TRUE);
}