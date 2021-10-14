#include "Button.h"

Button::Button(SDL_Renderer* t_renderer, TTF_Font* t_font, std::string t_name, float t_x, float t_y) :
    m_renderer(t_renderer),
    m_font(t_font),
    m_name(t_name),
    m_x(t_x),
    m_y(t_y)
{
    setupBackground();
    setupText();
}

Button::~Button()
{
    SDL_DestroyTexture(m_background);
}

void Button::draw()
{
    SDL_RenderCopy(m_renderer, m_background, NULL, &m_backgroundRect);
}

void Button::setupBackground()
{
    SDL_Surface * setupSurface = IMG_Load("assets/Button.png");

    if (setupSurface == nullptr) 
        printf("Image loading error::SDL_Error: %s\n", SDL_GetError());
    
    m_background = SDL_CreateTextureFromSurface(m_renderer, setupSurface);

    SDL_FreeSurface(setupSurface);

    if (m_background == nullptr) 
        printf("Texture creating error::SDL_Error: %s\n", SDL_GetError());
    
    SDL_QueryTexture(m_background, NULL, NULL, &m_backgroundRect.w, &m_backgroundRect.h);

    m_backgroundRect.x = m_x;
    m_backgroundRect.y = m_y;
}

void Button::setupText()
{

}