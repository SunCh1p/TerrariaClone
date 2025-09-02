#include "Game.h"

Game::Game(){
    m_gWindow = nullptr;
    m_gRenderer = nullptr;
    m_gScreenSurface = nullptr;
    m_framerate = 60;
    m_width = 720;
    m_height = 480;
    m_running = false;
}

bool Game::Init(int width, int height){
    m_width = width;
    m_height = height;
    //Initialization flag
    bool success { true };

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) == false )
    {
        SDL_Log( "SDL could not initialize! SDL error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window with renderer
        if( SDL_CreateWindowAndRenderer( "TerrariaClone", m_width, m_height, 0, &m_gWindow, &m_gRenderer ) == false )
        {
            SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError() );
            success = false;
        }
    }
    return success;
}

void Game::Run(){
    //quit flag
    m_running = true;
    //event data
    SDL_Event e;
    SDL_zero( e );
    //initialize delta time
    auto lastTime = std::chrono::steady_clock::now();
    double deltaTime { 0.0 };

    //default background color
    SDL_Color bgColor { 0xFF, 0xFF, 0xFF, 0xFF};

    while(m_running){
        //calculate delta time
        auto currentTime = std::chrono::steady_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(currentTime-lastTime).count()/1000000.0;

        m_processInput(e);
        m_update(deltaTime);
        m_render();
    } 
}

bool Game::Close(){
    //Destroy window
    SDL_DestroyRenderer(m_gRenderer);
    m_gRenderer = nullptr;
    SDL_DestroyWindow(m_gWindow);
    m_gWindow = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
    return true;
}

void Game::m_processInput(SDL_Event& e){
    //get event data
    while(SDL_PollEvent(&e)==true){
        if(e.type == SDL_EVENT_QUIT){
            //set running flag to false
            m_running = false;
        }
    }
}

void Game::m_update(double deltaTime){
    //nothing to update right now
}

void Game::m_render(){
    //Fill the background color
    SDL_SetRenderDrawColor(m_gRenderer, 255, 255, 255, 0xFF);
    SDL_RenderClear(m_gRenderer);

    //fill with other logic later

    //Update screen
    SDL_RenderPresent(m_gRenderer);
}

