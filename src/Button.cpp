#include "Button.h"
#include <iostream>

Button::Button(SDL_Renderer* t_renderer, TTF_Font* t_font, std::string t_name, float t_x, float t_y) :
    m_renderer(t_renderer),
    m_font(t_font),
    m_name(t_name),
    m_x(t_x),
    m_y(t_y),
    m_hovered{ false },
    m_clicked{ false },
    m_hoveredSizeChange{ 6.0f },
    m_clickedSizeChange{ 10.0f }
{
    setupBackground();
    setupText();
}

Button::~Button()
{
    SDL_DestroyTexture(m_background);
    
    if (m_command != nullptr)
        delete m_command;
}

void Button::draw()
{
    SDL_RenderCopy(m_renderer, m_background, NULL, &m_backgroundRect);
    SDL_RenderCopy(m_renderer, m_text, NULL, &m_textRect);
}

void Button::processEvents(SDL_Event & t_event)
{
    switch (t_event.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        if (contains(t_event.button.x, t_event.button.y))
        {
            if (m_command != nullptr)
                m_command->execute();
            
            if (!m_clicked)
                onClicked();
        }
        break;
    case SDL_MOUSEBUTTONUP:
        if (contains(t_event.button.x, t_event.button.y))
        {
            if (m_clicked)
                onUnclicked();
        }
        break;
    case SDL_MOUSEMOTION:
        if (contains(t_event.button.x, t_event.button.y))
        {
            if (!m_hovered)
                onHovered();
        }
        else
        {
            if (m_hovered)
                onUnhovered();
            if (m_clicked)
                onUnclicked();
        }
        break;
    }
}

void Button::setCommand(Command * t_command)
{
    m_command = t_command;
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
    SDL_Surface * setupSurface = TTF_RenderText_Solid(m_font, m_name.c_str(), SDL_Color{0,0,0});

    if (setupSurface == nullptr) 
        printf("Text loading error::SDL_Error: %s\n", SDL_GetError());

    m_text = SDL_CreateTextureFromSurface(m_renderer, setupSurface);
    SDL_FreeSurface(setupSurface);
    SDL_QueryTexture(m_text, NULL, NULL, &m_textRect.w, &m_textRect.h);

    // Centre the text in the button.
    m_textRect.x = m_x + (m_backgroundRect.w / 2.0f) - (m_textRect.w / 2.0f);
    m_textRect.y = m_y + (m_backgroundRect.h / 2.0f) - (m_textRect.h / 2.0f);

    if (m_text == nullptr)
        printf("Text loading error::SDL_Error: %s\n", SDL_GetError());
}

bool Button::contains(float t_x, float t_y)
{
    return t_x > m_x && t_x < m_x + m_backgroundRect.w
        && t_y > m_y && t_y < m_y + m_backgroundRect.h;
}

void Button::onHovered()
{
    m_hovered = true;
    m_backgroundRect.w += m_hoveredSizeChange;
    m_backgroundRect.h += m_hoveredSizeChange;
    m_backgroundRect.x -= m_hoveredSizeChange / 2.0f;
    m_backgroundRect.y -= m_hoveredSizeChange / 2.0f;

    m_textRect.w += m_hoveredSizeChange;
    m_textRect.h += m_hoveredSizeChange;
    m_textRect.x -= m_hoveredSizeChange / 2.0f;
    m_textRect.y -= m_hoveredSizeChange / 2.0f;
}

void Button::onUnhovered()
{
    m_hovered = false;
    m_backgroundRect.w -= m_hoveredSizeChange;
    m_backgroundRect.h -= m_hoveredSizeChange;
    m_backgroundRect.x += m_hoveredSizeChange / 2.0f;
    m_backgroundRect.y += m_hoveredSizeChange / 2.0f;

    m_textRect.w -= m_hoveredSizeChange;
    m_textRect.h -= m_hoveredSizeChange;
    m_textRect.x += m_hoveredSizeChange / 2.0f;
    m_textRect.y += m_hoveredSizeChange / 2.0f;
}

void Button::onClicked()
{
    m_clicked = true;
    m_backgroundRect.w -= m_clickedSizeChange;
    m_backgroundRect.h -= m_clickedSizeChange;
    m_backgroundRect.x += m_clickedSizeChange / 2.0f;
    m_backgroundRect.y += m_clickedSizeChange / 2.0f;

    m_textRect.w -= m_clickedSizeChange;
    m_textRect.h -= m_clickedSizeChange;
    m_textRect.x += m_clickedSizeChange / 2.0f;
    m_textRect.y += m_clickedSizeChange / 2.0f;
}

void Button::onUnclicked()
{
    m_clicked = false;
    m_backgroundRect.w += m_clickedSizeChange;
    m_backgroundRect.h += m_clickedSizeChange;
    m_backgroundRect.x -= m_clickedSizeChange / 2.0f;
    m_backgroundRect.y -= m_clickedSizeChange / 2.0f;

    m_textRect.w += m_clickedSizeChange;
    m_textRect.h += m_clickedSizeChange;
    m_textRect.x -= m_clickedSizeChange / 2.0f;
    m_textRect.y -= m_clickedSizeChange / 2.0f;
}