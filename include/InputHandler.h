#pragma once
#include <SDL3/SDL.h>
#include "GameCommands.h"
#include <memory>
#include <unordered_map>
#include <vector>
//Purpose of the input handler is to handle input given by any entity
class GameActor;

struct Input{

};

class InputHandler
{
    public:
        //Initializes default commands
        InputHandler();
        //Setter methods
        bool bindKeyToCommand(SDL_Keycode code, std::shared_ptr<Command> command);
        bool unbindKeyToCommand(SDL_Keycode code, std::shared_ptr<Command> command);
        bool resetBindingsToDefault();

        //action method
        bool executeCommand(SDL_Keycode code, GameActor& actor);

        //checker methods
        bool isKeyBound(SDL_Keycode code);
        bool isCommandBound(std::shared_ptr<Command> command);

        //getter methods
        SDL_Keycode getKeyForCommand(std::shared_ptr<Command> command);
        std::shared_ptr<Command> getCommandForKey(SDL_Keycode code);

    private:
        //Associative map command to bound key
        std::unordered_map<std::shared_ptr<Command>, SDL_Keycode> m_commandToKey;
        //Associative map binded key to command
        std::unordered_map<SDL_Keycode, std::shared_ptr<Command>> m_keyToCommand;

};