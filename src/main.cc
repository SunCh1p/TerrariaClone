//Using SDL, SDL_image, math, and strings
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include<SDL3_ttf/SDL_ttf.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if(!init()){
		SDL_Log("Failed to intiialize!\n");
	} else {
		// Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;

        //While the application is running
        while(!quit){
            while(SDL_PollEvent(&e)!=0){
                //User requests quit
                if(e.type == SDL_EVENT_QUIT){
                    quit = true;
                }
            }
        }
	}
    
    //Free resources and close SDL
    close();
	return 0;
}


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( !SDL_Init( SDL_INIT_VIDEO ) )
	{
		SDL_Log( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT, 0 );
		if( gWindow == NULL )
		{
			SDL_Log( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load font
    TTF_Font *font = TTF_OpenFont("./assets/fonts/Roboto/Roboto-VariableFont_wdth,wght.ttf",16);
    if(!font){
        SDL_Log("Font load error: %s", SDL_GetError());
        success = false;
    }

	return success;
}

void close()
{
	//Deallocate surface
	SDL_DestroySurface( gXOut );
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
