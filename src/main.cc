//Using SDL, SDL_image, math, and strings
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include<SDL3_ttf/SDL_ttf.h>
#include "Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	//create game instance
	Game game;

	//initialize the game
	if(game.Init(640, 480) == false){
		std::cerr << "Failed to initialize game" << std::endl;
		return 1;
	}

	//run the game
	game.Run();

	game.Close();

	return 0;
}

