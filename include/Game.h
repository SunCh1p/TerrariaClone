/*
    while(true){
        //handles user input that has happened since last call
        processInput();
        /advances game simulation one step
        update();
        //draws game so player can see what happened
        render();
    }
*/
#include <SDL3/SDL.h>
#include <iostream>
#include <chrono>

class Game{
    public:
        //Initializes the game object
        Game();
        //Initializes the game so that it can run
        bool Init(int width, int height);
        //Handles Game Loop, game must be initialized to run
        void Run();
        bool Close();
    private:
        //Takes user input
        void m_processInput(SDL_Event& e);
        //updates the game simulation
        void m_update(double deltaTime);
        //renders to the screen
        void m_render();

        //window we render to
        SDL_Window* m_gWindow;
        //renderer used to draw to the window
        SDL_Renderer* m_gRenderer;
        //surface contained by the window
        SDL_Surface* m_gScreenSurface;
        //framerate
        int m_framerate;
        int m_width;
        int m_height;
        bool m_running;
};
