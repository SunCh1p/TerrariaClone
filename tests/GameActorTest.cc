#include <catch2/catch_test_macros.hpp>
#include "GameActor.h"
#include <sstream>

GameActor actor;

TEST_CASE("Testing Game Actor", "[GameActor]"){
    
    SECTION("TESTING Fire"){
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        actor.Fire();
        std::cout.rdbuf(oldCout);
        REQUIRE(buffer.str() == "Game Actor fired\n");
        buffer.clear();
    }

    SECTION("Testing Jump"){
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        actor.Jump();
        std::cout.rdbuf(oldCout);
        REQUIRE(buffer.str() == "Game Actor Jumped\n");
        buffer.clear();

    }

    SECTION("Testing MoveRight"){
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        actor.MoveRight();
        std::cout.rdbuf(oldCout);
        REQUIRE(buffer.str() == "Game Actor moved right\n");
        buffer.clear();

    }

    SECTION("Testing MoveLeft"){
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        actor.MoveLeft();
        std::cout.rdbuf(oldCout);
        REQUIRE(buffer.str() == "Game Actor moved left\n");
        buffer.clear();
    }
}