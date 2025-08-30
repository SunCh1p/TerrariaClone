#include "InputHandler.h"

InputHandler::InputHandler(){
    //Bind 
}

bool InputHandler::bindKeyToCommand(SDL_Scancode code, std::shared_ptr<Command> command){
    bool successFlag = true;
    //check if key/command exists and already bound
    auto commandIt = m_commandToKey.find(command);
    auto codeIt = m_keyToCommand.find(code);
    if(commandIt != m_commandToKey.end() && commandIt->second != code){
        successFlag = false;
    }
    if(codeIt != m_keyToCommand.end() && codeIt->second != command){
        successFlag = false;
    }
    //if not already bound, bind
    if(successFlag){
        //bind via association through the hash tables
        m_commandToKey[command] = code;
        m_keyToCommand[code] = command;
    }
    return successFlag;
}

bool InputHandler::unbindKeyToCommand(SDL_Scancode code, std::shared_ptr<Command> command){
    bool successFlag = true;
    //make sure code is associated with command and vice versa
    if(isKeyBound(code) && getKeyForCommand(command) != code){
        successFlag = false;
    } else if(isCommandBound(command) && getCommandForKey(code) != command){
        successFlag = false;
    }
    //unbind is successflag is still true
    if(successFlag){
        m_commandToKey.erase(command);
        m_keyToCommand.erase(code);
    }
    return successFlag;
}

bool InputHandler::resetBindingsToDefault(){
    bool successFlag = true;
    //remove all existing bindings
    m_commandToKey.clear();
    m_keyToCommand.clear();

    //Apply left setting
    bool bindMoveLeftFlag = bindKeyToCommand(SDL_SCANCODE_A, std::make_shared<MoveLeft>());
    bool bindMoveRightFlag = bindKeyToCommand(SDL_SCANCODE_D, std::make_shared<MoveRight>());
    bool bindJumpFlag = bindKeyToCommand(SDL_SCANCODE_SPACE, std::make_shared<Jump>());

    //Must bind Fire command with mouse separately


    return successFlag;


}

bool InputHandler::executeCommand(SDL_Scancode code, GameActor& actor){
    bool successFlag = true;
    if(!isKeyBound(code)){
        successFlag = false;
    }
    //get the commaned for the key
    std::shared_ptr<Command> command = nullptr;
    if(successFlag){
        command = getCommandForKey(code);
    }
    //check if command was retrieved
    if(command == nullptr){
        successFlag = false;
    }
    //execute command
    if(successFlag){
        command->execute(actor);
    }
    //return flag
    return successFlag;
}

bool InputHandler::isKeyBound(SDL_Scancode code){
    bool successFlag = true;
    //check if key is already bound
    if(m_keyToCommand.find(code) == m_keyToCommand.end()){
        //if not found, false
        successFlag = false;
    }
    return successFlag;
}

bool InputHandler::isCommandBound(std::shared_ptr<Command> command){
    bool successFlag = true;
    //check if command is already bound
    if(m_commandToKey.find(command) == m_commandToKey.end()){
        //if not found, false
        successFlag = false;
    }
    return successFlag;
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