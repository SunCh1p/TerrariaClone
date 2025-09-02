#include "GameCommands.h"
#include <catch2/catch_test_macros.hpp>


TEST_CASE("Testing Jump command object", "[Jump]"){
    GameActor actor;
    Jump jump;
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    jump.execute(actor);
    std::cout.rdbuf(oldCout);
    REQUIRE(buffer.str() == "Game Actor Jumped\n");
    buffer.clear();
}

TEST_CASE("Testing Fire command object", "[Fire]"){
    GameActor actor;
    Fire fire;
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    fire.execute(actor);
    std::cout.rdbuf(oldCout);
    REQUIRE(buffer.str() == "Game Actor fired\n");
    buffer.clear();
}

TEST_CASE("Testing MoveRight command object", "[MoveRight]"){
    GameActor actor;
    MoveRight moveRight;
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    moveRight.execute(actor);
    std::cout.rdbuf(oldCout);
    REQUIRE(buffer.str() == "Game Actor moved right\n");
    buffer.clear();
}

TEST_CASE("Testing MoveLeft command object", "[MoveLeft]"){
    GameActor actor;
    MoveLeft moveLeft;
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    moveLeft.execute(actor);
    std::cout.rdbuf(oldCout);
    REQUIRE(buffer.str() == "Game Actor moved left\n");
    buffer.clear();
}