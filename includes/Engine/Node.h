#pragma once
#include <Controller.h>
#include <GLDriver.h>

namespace Engine{
    class Node :public INode
	{
		public:
			void addToProcess();
			void removeFromProcess();

			void addToCursorProcess();
			void removeFromCursorProcess();

			void addToInputProcess();
			void removeFromInputProcess();

			void addToQueueFree();

			GraphicsDrivers::Interfaces::IWindow* window();
	};
}