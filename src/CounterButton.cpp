#include "CounterButton.h"

CounterButton::CounterButton(SDL_Renderer* t_renderer, TTF_Font* t_font, std::string t_name, float t_x, float t_y) :
    Button(t_renderer, t_font, t_name, t_x, t_y),
    m_count{ 0 }
{
    setupCounterText(m_count);
}

CounterButton::~CounterButton()
{
    SDL_DestroyTexture(m_background);
}

void CounterButton::draw()
{
    SDL_RenderCopy(m_renderer, m_background, NULL, &m_backgroundRect);
    SDL_RenderCopy(m_renderer, m_text, NULL, &m_textRect);
    SDL_RenderCopy(m_renderer, m_counterText, NULL, &m_counterTextRect);
}

void CounterButton::incrementCounter()
{
    m_count++;
    setupCounterText(m_count);
}

void CounterButton::decrementCounter()
{
    m_count--;
    setupCounterText(m_count);
}

void CounterButton::setupCounterText(int t_count)
{
    SDL_Surface * setupSurface = TTF_RenderText_Solid(m_font, std::to_string(t_count).c_str(), SDL_Color{0,0,0});

    if (setupSurface == nullptr) 
        printf("Text loading error::SDL_Error: %s\n", SDL_GetError());

    m_counterText = SDL_CreateTextureFromSurface(m_renderer, setupSurface);
    SDL_FreeSurface(setupSurface);
    SDL_QueryTexture(m_counterText, NULL, NULL, &m_counterTextRect.w, &m_counterTextRect.h);

    // Centre the text in the button.
    m_counterTextRect.x = m_x + (m_backgroundRect.w / 2.0f) - (m_counterTextRect.w / 2.0f);
    m_counterTextRect.y = m_y + (m_backgroundRect.h / 1.3f) - (m_counterTextRect.h / 2.0f);

    if (m_counterText == nullptr)
        printf("Text loading error::SDL_Error: %s\n", SDL_GetError());
}