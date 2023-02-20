#include <Node.h>

void Engine::Node::addToProcess()
{
	Engine::Controller::instance()->addToProcess(this);
}

void Engine::Node::removeFromProcess()
{
	Engine::Controller::instance()->removeFromProcess(this);
}

void Engine::Node::addToCursorProcess()
{
	Engine::Controller::instance()->addToCursorProcess(this);
}

void Engine::Node::removeFromCursorProcess()
{
	Engine::Controller::instance()->removeFromCursorProcess(this);
}

void Engine::Node::addToInputProcess()
{
	Engine::Controller::instance()->addToInputProcess(this);
}

void Engine::Node::removeFromInputProcess()
{
	Engine::Controller::instance()->removeFromCursorProcess(this);
}

void Engine::Node::addToQueueFree()
{
	Engine::Controller::instance()->addToQueueFree(this);
}
GraphicsDrivers::Interfaces::IWindow* Engine::Node::window(){
	return GraphicsDrivers::GLDriver::window();
}
