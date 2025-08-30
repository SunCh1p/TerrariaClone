#include <catch2/catch_test_macros.hpp>
#include "InputHandler.h"
#include <sstream>


TEST_CASE("Testing Game Actor"){
    GameActor actor;
    //Redirect cout to stringstream buffer
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    //Test jump from game actor
    SECTION("Testing Jump"){
        actor.Jump();
        REQUIRE(buffer.str() == "Game Actor Jumped\n");
        buffer.clear();
    }

    //restore cout
    std::cout.rdbuf(oldCout);
}