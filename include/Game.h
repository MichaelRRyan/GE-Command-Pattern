#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Game
{
public:

    Game();
    ~Game();
    void run();

private:

    void processEvents();
    void update();
    void render();

    void cleanUp();

    bool m_isRunning;

    //Render Window
	SDL_Window* window = NULL;
	
	//Frame or Surface to Render to
	SDL_Surface* frame = NULL;

};

#endif // !GAME_H