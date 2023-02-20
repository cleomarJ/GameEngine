#pragma once
#include <set>
#include <vector>
#include <string>
#include <mutex>
#include <thread>
#include <INode.h>
#include <Input.h>

namespace Engine {
	class Controller
	{

		public:
			Controller(Controller& other) = delete;
			void operator=(const Controller&) = delete;

			void addToProcess(INode*);
			void removeFromProcess(INode*);

			void addToCursorProcess(INode*);
			void removeFromCursorProcess(INode*);

			void addToInputProcess(INode*);
			void removeFromInputProcess(INode*);

			void addToQueueFree(INode*);
			void executeQueueFree();

			void process();
			void input(Input::Input& input);

			
			static Controller* instance();
		private:
            static Controller* controller_;
            Controller();
			std::set<INode*> processNodes;
			std::set<INode*> cursorProcessNodes;
			std::set<INode*> inputProcessNodes;

			std::vector<INode*> queueFree;

			std::mutex processMutex;
			std::mutex cursorMutex;
			std::mutex inputMutex;
			std::mutex queueFreeMutex;
	};
};
