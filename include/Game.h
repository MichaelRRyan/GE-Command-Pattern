#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>
#include "Button.h"
#include "CounterButton.h"
#include "AddMaterialCommand.h"
#include "UndoCommand.h"
#include "RedoCommand.h"
#include "CommandHistory.h"

const int SCREEN_WIDTH = 980;
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
    void setupButtonsAndCommands();

    bool m_isRunning;

    std::vector<Button *> m_buttons;

    TTF_Font* m_font;

    //Render Window
	SDL_Window* m_window = NULL;
	
	SDL_Renderer* m_renderer;

    CommandHistory m_commandHistory;

};

#endif // !GAME_H