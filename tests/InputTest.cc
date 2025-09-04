#include "InputHandler.h"
#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("Testing inputsForEquality", "[Input]"){
    //TODO: Make this test case better when it comes to readability
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
    REQUIRE(i_fire == i_fire);
    REQUIRE(i_fire != i_moveLeft);
    REQUIRE(i_fire != i_moveRight);
    REQUIRE(i_fire != i_jump);
    REQUIRE(i_moveLeft == i_moveLeft);
    REQUIRE(i_moveLeft != i_fire);
    REQUIRE(i_moveLeft != i_moveRight);
    REQUIRE(i_moveLeft != i_jump);
    REQUIRE(i_moveRight == i_moveRight);
    REQUIRE(i_moveRight != i_fire);
    REQUIRE(i_moveRight != i_moveLeft);
    REQUIRE(i_moveRight != i_jump);
    REQUIRE(i_jump == i_jump);
    REQUIRE(i_jump != i_fire);
    REQUIRE(i_jump != i_moveLeft);
    REQUIRE(i_jump != i_moveRight);
};