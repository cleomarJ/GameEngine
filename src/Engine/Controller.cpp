#include <Controller.h>
Engine::Controller* Engine::Controller::controller_ = nullptr;
Engine::Controller::Controller(){
    
}
void Engine::Controller::addToProcess(INode* node){
    processMutex.lock();
    processNodes.insert(node);
    processMutex.unlock();
}

void Engine::Controller::removeFromProcess(INode* node){
    processMutex.lock();
    processNodes.erase(node);
    processMutex.unlock();
}

void Engine::Controller::addToCursorProcess(INode* node){
    cursorMutex.lock();
    cursorProcessNodes.insert(node);
    cursorMutex.unlock();
}

void Engine::Controller::removeFromCursorProcess(INode* node){
    cursorMutex.lock();
    cursorProcessNodes.erase(node);
    cursorMutex.unlock();
}

void Engine::Controller::addToInputProcess(INode* node){
    inputMutex.lock();
    inputProcessNodes.insert(node);
    inputMutex.unlock();
}

void Engine::Controller::removeFromInputProcess(INode* node){
    inputMutex.lock();
    inputProcessNodes.erase(node);
    inputMutex.unlock();
}

void Engine::Controller::addToQueueFree(INode* node){
    node->setActive(false);
    removeFromProcess(node);
    removeFromCursorProcess(node);
    removeFromInputProcess(node);

    queueFreeMutex.lock();
    queueFree.push_back(node);
    queueFreeMutex.unlock();
}

void Engine::Controller::executeQueueFree(){
    if(!queueFreeMutex.try_lock()){
        return;
    }

    if(this->queueFree.empty()){
        queueFreeMutex.unlock();
        return;
    }

    std::vector<INode*> queueFree = this->queueFree;

    queueFreeMutex.unlock();

    std::thread([](std::vector<INode*> queueFree){
        for(INode* node :queueFree){
            delete node;
        }
    },queueFree).detach();
}

void Engine::Controller::process(){
    executeQueueFree();
    processMutex.lock();
    if(processNodes.empty()){
        processMutex.unlock();
        return;
    }
    for(INode* node: processNodes){
        if(!node->isActive()){
            continue;
        }
        node->process();
    }
    processMutex.unlock();

}
void Engine::Controller::input(Input::Input& input){

    inputMutex.lock();
    if(inputProcessNodes.empty()){
        inputMutex.unlock();
        return;
    }
    for(INode* node: inputProcessNodes){
        if(!node->isActive()){
            continue;
        }
        node->input(input);
    }
    inputMutex.unlock();

}

Engine::Controller* Engine::Controller::instance(){
    if(controller_ == nullptr){
        controller_ = new Engine::Controller();
    }
    return controller_;
}