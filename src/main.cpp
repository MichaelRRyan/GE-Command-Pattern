#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main( int argc, char* argv[] )
{
	// Handle arguments (Note C style)
	printf( "argc = %d\n", argc );
    for( int i = 0; i < argc; ++i ) {
        printf( "argv[ %d ] = %s\n", i, argv[ i ] );
    }

	//Render Window
	SDL_Window* window = NULL;
	
	//Frame or Surface to Render to
	SDL_Surface* frame = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "Initialization Error::SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "Visual Studio Code SDL Starter Kit (Windows 10 MSYS64 SDL2)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window Creation Error::SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get Window Frame to Render to
			frame = SDL_GetWindowSurface( window );

			//Fill the Frame with Red
			SDL_FillRect( frame, NULL, SDL_MapRGB( frame->format, 0xFF, 0x00, 0x00 ) );
			
			//Update the surface
			SDL_UpdateWindowSurface( window );

			//Wait
			SDL_Delay( 10000 );
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
