#include "Game.h"

Game::Game() : 
    m_isRunning{ false }
{
    //Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "Initialization Error::SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Render Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window Creation Error::SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get Window Frame to Render to
			frame = SDL_GetWindowSurface( window );
		}
	}
}

Game::~Game()
{ 
    cleanUp(); 
}

void Game::run()
{
    m_isRunning = true;

    while (m_isRunning)
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0)
    {
        if(e.type == SDL_QUIT)
        {
            m_isRunning = false;
        }
    }
}

void Game::update()
{

}

void Game::render()
{
    //Fill the Frame with Red
    SDL_FillRect( frame, NULL, SDL_MapRGB( frame->format, 0xFF, 0x00, 0x00 ) );
    
    //Update the surface
    SDL_UpdateWindowSurface( window );
}

void Game::cleanUp()
{
    //Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();
}