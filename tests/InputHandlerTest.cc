#include "InputHandler.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("inputHandler:bindKeyToCommand", "[bindKeyToCommand]"){
    //declare different input types
    Input i_fire = {
        .device = InputDeviceType::Mouse,
        .mouseButton = SDL_BUTTON_LEFT
    };
    Input i_moveLeft = {
        .device = InputDeviceType::Keyboard,
        .key = SDLK_A
    };
    Input i_moveRight = {
        .device = InputDeviceType::Keyboard,
        .key = SDLK_D
    };
    Input i_jump = {
        .device = InputDeviceType::Keyboard,
        .key = SDLK_SPACE
    };
    //declare commands to associate with inputs
    std::shared_ptr<Fire> firePtr = std::make_shared<Fire>();
    std::shared_ptr<Jump> jumpPtr = std::make_shared<Jump>();
    std::shared_ptr<MoveLeft> moveLeftPtr = std::make_shared<MoveLeft>();
    std::shared_ptr<MoveRight> moveRightPtr = std::make_shared<MoveRight>();
    //declare inputhandler
    InputHandler inputHandler;
    //check if binding returns true if input isn't already recorded in object
    //binding fire
    REQUIRE(inputHandler.bindKeyToCommand(i_fire, firePtr) == true);
    REQUIRE(inputHandler.bindKeyToCommand(i_fire, jumpPtr) == false);
    REQUIRE(inputHandler.bindKeyToCommand(i_fire, moveLeftPtr) == false);
    REQUIRE(inputHandler.bindKeyToCommand(i_fire, moveRightPtr) == false);
    //binding moveLeft
    REQUIRE(inputHandler.bindKeyToCommand(i_moveLeft, moveLeftPtr) == true);
    REQUIRE(inputHandler.bindKeyToCommand(i_moveLeft, jumpPtr) == false);
    REQUIRE(inputHandler.bindKeyToCommand(i_moveLeft, firePtr) == false);
    REQUIRE(inputHandler.bindKeyToCommand(i_moveLeft, moveRightPtr) == false);
    //binding moveRight
    REQUIRE(inputHandler.bindKeyToCommand(i_moveRight, moveRightPtr) == true);
    REQUIRE(inputHandler.bindKeyToCommand(i_moveRight, jumpPtr) == false);
    REQUIRE(inputHandler.bindKeyToCommand(i_moveRight, firePtr) == false);
    REQUIRE(inputHandler.bindKeyToCommand(i_moveRight, moveLeftPtr) == false);
    //binding jump
    REQUIRE(inputHandler.bindKeyToCommand(i_jump, jumpPtr) == true);
    REQUIRE(inputHandler.bindKeyToCommand(i_jump, moveRightPtr) == false);
    REQUIRE(inputHandler.bindKeyToCommand(i_jump, firePtr) == false);
    REQUIRE(inputHandler.bindKeyToCommand(i_jump, moveLeftPtr) == false);
};