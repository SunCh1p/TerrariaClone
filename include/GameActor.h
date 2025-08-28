#pragma once
#include <iostream>

class GameActor{
    public:
        virtual void Jump(){
            std::cout << "Game Actor Jumped" << std::endl;
        }
        virtual void MoveLeft(){
            std::cout << "Game Actor moved left" << std::endl;
        }
        virtual void MoveRight(){
            std::cout << "Game Actor moved right" << std::endl;
        }
        virtual void Fire(){
            std::cout << "Game Actor fired" << std::endl;
        }
    
    private:
};