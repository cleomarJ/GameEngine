#include <MainScene.h>
#include <iostream>

Scenes::MainScene::MainScene()
{
	addToInputProcess();
	//addToCursorProcess(); 
	//addToProcess();
}

void Scenes::MainScene::input(Input::Input& input)
{

	std::cout << input.getName()<<std::endl;
}

void Scenes::MainScene::cursor(double xPos, double yPos)
{
	std::cout << "x=" << xPos << ",y=" << yPos << std::endl;
}

void Scenes::MainScene::process()
{
	if (Input::InputControl::instance()->isKeyPressed("jump")) {
		std::cout << "pressionado" << std::endl;
	}
}