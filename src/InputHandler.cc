#include "InputHandler.h"

InputHandler::InputHandler(){
    //Bind 
}

bool InputHandler::bindKeyToCommand(SDL_Scancode code, std::shared_ptr<Command> command){

}

bool InputHandler::unbindKeyToCommand(SDL_Scancode code, std::shared_ptr<Command> command){

}

bool InputHandler::resetBindingsToDefault(){

}

bool InputHandler::executeCommand(SDL_Scancode code){

}

SDL_Scancode InputHandler::getKeyForCommand(std::shared_ptr<Command> command){
    //If key not found, return unknown flag
    if(m_commandToKey.find(command) == m_commandToKey.end()){
        return SDL_SCANCODE_UNKNOWN;
    }
    //other wise return key to the command
    return m_commandToKey[command];
}

std::shared_ptr<Command> InputHandler::getCommandForKey(SDL_Scancode code){
    if(m_keyToCommand.find(code) == m_keyToCommand.end()){
        return nullptr;
    }
    return m_keyToCommand[code];
}