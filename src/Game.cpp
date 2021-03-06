#include "Game.h"

Game::Game() : 
    m_isRunning{ false }
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    
    //Create window
    m_window = SDL_CreateWindow("Render Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    
    if (m_window == nullptr)
        printf("Window Creation Error::SDL_Error: %s\n", SDL_GetError());
    
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if (m_renderer == nullptr)
        printf("Renderer Creation Error::SDL_Error: %s\n", SDL_GetError());
    
    m_font = TTF_OpenFont("assets/Gwibble.ttf", 32);

    if (m_font == nullptr)
        printf("Open Font Error::SDL_Error: %s\n", SDL_GetError());

    setupButtonsAndCommands();
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

        for (Button * button : m_buttons)
            button->processEvents(e);
    }
}

void Game::update()
{

}

void Game::render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    for (Button * button : m_buttons)
        button->draw();

    SDL_RenderPresent(m_renderer);
}

void Game::cleanUp()
{
    //Destroy window
	SDL_DestroyWindow( m_window );

	//Quit SDL subsystems
	SDL_Quit();
}

void Game::setupButtonsAndCommands()
{
    CounterButton * btn = new CounterButton(m_renderer, m_font, "Lego brick", 20.0f, 20.0f);
    m_buttons.push_back(btn);
    Command * cmd = new AddMaterialCommand(btn, m_commandHistory, m_factoryOrders, new LegoBrickFactory());
    btn->setCommand(cmd);

    btn = new CounterButton(m_renderer, m_font, "Mud brick", 340.0f, 20.0f);
    m_buttons.push_back(btn);
    cmd = new AddMaterialCommand(btn, m_commandHistory, m_factoryOrders, new MudBrickFactory());
    btn->setCommand(cmd);

    btn = new CounterButton(m_renderer, m_font, "Clay brick", 660.0f, 20.0f);
    m_buttons.push_back(btn);
    cmd = new AddMaterialCommand(btn, m_commandHistory, m_factoryOrders, new ClayBrickFactory());
    btn->setCommand(cmd);

    m_buttons.push_back(new Button(m_renderer, m_font, "Undo", 20.0f, 380.0f));
    cmd = new UndoCommand(m_commandHistory);
    m_buttons.back()->setCommand(cmd);

    m_buttons.push_back(new Button(m_renderer, m_font, "Build", 340.0f, 380.0f));
    m_buttons.back()->setCommand(new BuildCommand(m_factoryOrders));

    m_buttons.push_back(new Button(m_renderer, m_font, "Redo", 660.0f, 380.0f));
    cmd = new RedoCommand(m_commandHistory);
    m_buttons.back()->setCommand(cmd);
}