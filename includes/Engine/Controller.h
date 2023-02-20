#pragma once
#include <set>
#include <vector>
#include <string>
#include <mutex>
#include <thread>
#include <INode.h>

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
			void excuteQueueFree();

			void process();
			void input(std::string& name, size_t key, bool pressed);
			void cursor(double xMov, double yMov);

			
			static Controller* getInstance();
		private:
            static Controller* controller_;
            Controller();
			std::set<INode*> processEntities;
			std::set<INode*> cursorProcess;
			std::set<INode*> inputProcess;

			std::vector<INode*> queueFree;

			std::mutex processMutex;
			std::mutex cursorMutex;
			std::mutex inputMutex;
			std::mutex queueFreeMutex;
	};
};
