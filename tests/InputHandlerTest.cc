#include "InputHandler.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("inputHandler:bindInputToCommand", "[bindInputToCommand]"){
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
    REQUIRE(inputHandler.bindInputToCommand(i_fire, firePtr) == true);
    REQUIRE(inputHandler.bindInputToCommand(i_fire, jumpPtr) == false);
    REQUIRE(inputHandler.bindInputToCommand(i_fire, moveLeftPtr) == false);
    REQUIRE(inputHandler.bindInputToCommand(i_fire, moveRightPtr) == false);
    //binding moveLeft
    REQUIRE(inputHandler.bindInputToCommand(i_moveLeft, moveLeftPtr) == true);
    REQUIRE(inputHandler.bindInputToCommand(i_moveLeft, jumpPtr) == false);
    REQUIRE(inputHandler.bindInputToCommand(i_moveLeft, firePtr) == false);
    REQUIRE(inputHandler.bindInputToCommand(i_moveLeft, moveRightPtr) == false);
    //binding moveRight
    REQUIRE(inputHandler.bindInputToCommand(i_moveRight, moveRightPtr) == true);
    REQUIRE(inputHandler.bindInputToCommand(i_moveRight, jumpPtr) == false);
    REQUIRE(inputHandler.bindInputToCommand(i_moveRight, firePtr) == false);
    REQUIRE(inputHandler.bindInputToCommand(i_moveRight, moveLeftPtr) == false);
    //binding jump
    REQUIRE(inputHandler.bindInputToCommand(i_jump, jumpPtr) == true);
    REQUIRE(inputHandler.bindInputToCommand(i_jump, moveRightPtr) == false);
    REQUIRE(inputHandler.bindInputToCommand(i_jump, firePtr) == false);
    REQUIRE(inputHandler.bindInputToCommand(i_jump, moveLeftPtr) == false);
};

TEST_CASE("inputHandler:isInputBound", "[isInputBound]"){
    //declare input type
    Input i_fire = {
        .device = InputDeviceType::Mouse,
        .mouseButton = SDL_BUTTON_LEFT
    };
    //declare associated command
    std::shared_ptr<Fire> firePtr = std::make_shared<Fire>();
    //declare input handler
    InputHandler inputHandler;
    REQUIRE(inputHandler.isInputBound(i_fire) == false);
    inputHandler.bindInputToCommand(i_fire, firePtr);
    REQUIRE(inputHandler.isInputBound(i_fire) == true);
};

TEST_CASE("inputHandler:isCommandBound", "[isCommandBound]"){
    //declare input type
    Input i_fire = {
        .device = InputDeviceType::Mouse,
        .mouseButton = SDL_BUTTON_LEFT
    };
    //declare associated command
    std::shared_ptr<Fire> firePtr = std::make_shared<Fire>();
    //declare input handler
    InputHandler inputHandler;
    REQUIRE(inputHandler.isCommandBound(firePtr) == false);
    inputHandler.bindInputToCommand(i_fire, firePtr);
    REQUIRE(inputHandler.isCommandBound(firePtr) == true);
};

TEST_CASE("inputHandler:getInputForCommand", "[getInputForCommand]"){
    //declare input type
    Input i_fire = {
        .device = InputDeviceType::Mouse,
        .mouseButton = SDL_BUTTON_LEFT
    };
    Input unknown = {
        .device = InputDeviceType::Unknown,
        .unknown = InputDeviceType::Unknown
    };
    //declare associated command
    std::shared_ptr<Fire> firePtr = std::make_shared<Fire>();
    //declare input handler
    InputHandler inputHandler;
    REQUIRE(inputHandler.getInputForCommand(firePtr) == unknown);
    inputHandler.bindInputToCommand(i_fire, firePtr);
    REQUIRE(inputHandler.getInputForCommand(firePtr) == i_fire);
}

// TEST_CASE("inputHandler:getCommandForInput", "[getCommandForInput]"){
//     //declare input type
//     Input i_fire = {
//         .device = InputDeviceType::Mouse,
//         .mouseButton = SDL_BUTTON_LEFT
//     };
//     Input unknown = {
//         .device = InputDeviceType::Unknown,
//         .unknown = InputDeviceType::Unknown
//     };
//     //declare associated command
//     std::shared_ptr<Fire> firePtr = std::make_shared<Fire>();
//     //declare input handler
//     InputHandler inputHandler;
//     REQUIRE(inputHandler.getCommandForInput(i_fire) == nullptr);
//     inputHandler.bindInputToCommand(i_fire, firePtr);
//     REQUIRE(*inputHandler.getCommandForInput(i_fire) == *firePtr);
// }