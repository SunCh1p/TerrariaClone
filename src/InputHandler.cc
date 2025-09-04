#include "InputHandler.h"

InputHandler::InputHandler(){
    //Bind 
}

bool InputHandler::bindInputToCommand(Input input, std::shared_ptr<Command> command){
    bool successFlag = true;
    //check if key/command exists and already bound
    auto commandIt = m_commandToInput.find(command);
    auto inputIt = m_inputToCommand.find(input);
    if(commandIt != m_commandToInput.end() && commandIt->second != input){
        successFlag = false;
    }
    if(inputIt != m_inputToCommand.end() && inputIt->second != command){
        successFlag = false;
    }
    //if not already bound, bind
    if(successFlag){
        //bind via association through the hash tables
        m_commandToInput[command] = input;
        m_inputToCommand[input] = command;
    }
    return successFlag;
}

// bool InputHandler::unbindInputToCommand(SDL_Keycode code, std::shared_ptr<Command> command){
//     bool successFlag = true;
//     //make sure code is associated with command and vice versa
//     if(isKeyBound(code) && getKeyForCommand(command) != code){
//         successFlag = false;
//     } else if(isCommandBound(command) && getCommandForKey(code) != command){
//         successFlag = false;
//     }
//     //unbind is successflag is still true
//     if(successFlag){
//         m_commandToKey.erase(command);
//         m_keyToCommand.erase(code);
//     }
//     return successFlag;
// }

// bool InputHandler::resetBindingsToDefault(){
//     bool successFlag = true;
//     //remove all existing bindings
//     m_commandToKey.clear();
//     m_keyToCommand.clear();

//     //Apply left setting
//     bool bindMoveLeftFlag = bindInputToCommand(SDLK_A, std::make_shared<MoveLeft>());
//     bool bindMoveRightFlag = bindInputToCommand(SDLK_D, std::make_shared<MoveRight>());
//     bool bindJumpFlag = bindInputToCommand(SDLK_SPACE, std::make_shared<Jump>());
//     //TODO: bind fire command separately with mouse
//     bool bindFireFlag = bindInputToCommand(SDLK_F, std::make_shared<Fire>());

//     return successFlag;


// }

// bool InputHandler::executeCommand(SDL_Keycode code, GameActor& actor){
//     bool successFlag = true;
//     if(!isKeyBound(code)){
//         successFlag = false;
//     }
//     //get the commaned for the key
//     std::shared_ptr<Command> command = nullptr;
//     if(successFlag){
//         command = getCommandForKey(code);
//     }
//     //check if command was retrieved
//     if(command == nullptr){
//         successFlag = false;
//     }
//     //execute command
//     if(successFlag){
//         command->execute(actor);
//     }
//     //return flag
//     return successFlag;
// }

bool InputHandler::isInputBound(Input input){
    bool successFlag = true;
    //check if key is already bound
    if(m_inputToCommand.find(input) == m_inputToCommand.end()){
        //if not found, false
        successFlag = false;
    }
    return successFlag;
}

bool InputHandler::isCommandBound(std::shared_ptr<Command> command){
    bool successFlag = true;
    //check if command is already bound
    if(m_commandToInput.find(command) == m_commandToInput.end()){
        //if not found, false
        successFlag = false;
    }
    return successFlag;
}    

const Input InputHandler::getInputForCommand(std::shared_ptr<Command> command){
    //If key not found, return unknown flag
    if(m_commandToInput.find(command) == m_commandToInput.end()){
        return Input{
            .device = InputDeviceType::Unknown,
            .unknown = InputDeviceType::Unknown
        };
    }
    //other wise return key to the command
    return m_commandToInput[command];
}

const std::shared_ptr<Command> InputHandler::getCommandForInput(Input input){
    if(m_inputToCommand.find(input) == m_inputToCommand.end()){
        return nullptr;
    }
    return m_inputToCommand[input];
}