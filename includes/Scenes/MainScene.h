#pragma once
#include <Node.h>
#include <InputControl.h>

namespace Scenes {
	class MainScene : public Engine::Node
	{
		public:
			MainScene();
			void input(Input::Input& input);
			void cursor(double xPos, double yPos);
			void process();
	};
};

