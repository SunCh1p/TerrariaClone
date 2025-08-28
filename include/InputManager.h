#pragma once
#include <SDL3/SDL.h>
#include "GameCommands.h"
#include <unordered_map>

class GameActor;

class InputHandler
{
    public:
        // Method to bind character
        Command* handleInput();

        // Methods to bind commands

    private:
        Command* one;
        Command* two;
        Command* three;
        Command* four;

};