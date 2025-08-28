#pragma once
#include "command.h"
#include "GameActor.h"

class Jump : public Command {
    public:
        virtual void execute(GameActor& actor){
            actor.Jump();
        }
};

class MoveLeft : public Command {
    public:
        virtual void execute(GameActor& actor){
            actor.MoveLeft();
        }
};

class MoveRight : public Command {
    public:
        virtual void execute(GameActor& actor){
            actor.MoveRight();
        }
};

class Fire : public Command {
    public:
        virtual void execute(GameActor& actor){
            actor.Fire();
        }
};