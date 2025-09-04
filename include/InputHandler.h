#pragma once
#include <SDL3/SDL.h>
#include "GameCommands.h"
#include <memory>
#include <unordered_map>
#include <vector>
//Purpose of the input handler is to handle input given by any entity
class GameActor;

//the following section is written with the assistance of chatgpt because I had no idea how to approach this
//and the solution is good enough for my purposes
enum class InputDeviceType{
    Keyboard,
    Mouse,
    Unknown
};

struct Input{
    InputDeviceType device;
    union {
        SDL_Keycode key;
        Uint8 mouseButton;
        InputDeviceType unknown;
    };
    bool operator==(const Input& other) const{
        if(device != other.device){
            return false;
        }
        switch(device){
            case InputDeviceType::Keyboard: return key == other.key;
            case InputDeviceType::Mouse: return mouseButton == other.mouseButton;
            default: return true;
        }
    }
    bool operator!=(const Input& other) const{
        return !(*this == other);
    }
};

struct InputHash {
    std::size_t operator()(const Input& i) const {
        std::size_t h1 = std::hash<int>()(static_cast<int>(i.device));
        std::size_t h2 = 0;
        switch (i.device) {
            case InputDeviceType::Keyboard: h2 = std::hash<SDL_Keycode>()(i.key); break;
            case InputDeviceType::Mouse:    h2 = std::hash<Uint8>()(i.mouseButton); break;
            default:                        h2 = 0; break;
        }
        return h1 ^ (h2 << 1);
    }
};
//end of chatgpt section

class InputHandler
{
    public:
        //Initializes default commands
        InputHandler();
        //Setter methods
        bool bindInputToCommand(Input input, std::shared_ptr<Command> command);
        //bool unbindKeyToCommand(SDL_Keycode code, std::shared_ptr<Command> command);
        //bool resetBindingsToDefault();

        //action method
        //bool executeCommand(SDL_Keycode code, GameActor& actor);

        //checker methods
        bool isInputBound(Input input);
        bool isCommandBound(std::shared_ptr<Command> command);

        //getter methods
        const Input getInputForCommand(std::shared_ptr<Command> command);
        const std::shared_ptr<Command> getCommandForInput(Input input);

    private:
        //Associative map command to bound key
        std::unordered_map<std::shared_ptr<Command>, Input> m_commandToInput;
        //Associative map binded key to command
        std::unordered_map<Input, std::shared_ptr<Command>, InputHash> m_inputToCommand;

};