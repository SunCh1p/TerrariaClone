#include <catch2/catch_test_macros.hpp>
#include "GameActor.h"
#include <sstream>

GameActor actor;

TEST_CASE("Testing Game Actor Jump", "[GameActor]"){
    SECTION("Testing Jump"){
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        actor.Jump();
        REQUIRE(buffer.str() == "Game Actor Jumped\n");
        buffer.clear();
        std::cout.rdbuf(oldCout);

    }
}

TEST_CASE("Testing Game Actor Fire", "[GameActor]"){
    SECTION("TESTING Fire"){
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        actor.Fire();
        REQUIRE(buffer.str() == "Game Actor fired\n");
        buffer.clear();
        std::cout.rdbuf(oldCout);
    }
}

TEST_CASE("Testing Game Actor MoveRight", "[GameActor]"){
    SECTION("Testing MoveRight"){
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        actor.MoveRight();
        REQUIRE(buffer.str() == "Game Actor moved right\n");
        buffer.clear();
        std::cout.rdbuf(oldCout);

    }
}

TEST_CASE("Testing Game Actor MoveLeft", "[GameActor]"){
    SECTION("Testing MoveLeft"){
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        actor.MoveLeft();
        REQUIRE(buffer.str() == "Game Actor moved left\n");
        buffer.clear();
        std::cout.rdbuf(oldCout);
    }
}