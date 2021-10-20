#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include "Command.h"

class Button
{
public:

    Button(SDL_Renderer* t_renderer, TTF_Font* t_font, std::string t_name, float t_x, float t_y);
    virtual ~Button();
    virtual void draw();

    void processEvents(SDL_Event & t_event);

    void setCommand(Command * t_command);

protected:

    std::string m_name;

    float m_x;
    float m_y;

    SDL_Renderer * m_renderer;

    TTF_Font * m_font;

    SDL_Texture * m_background;
    SDL_Texture * m_text;

    SDL_Rect m_backgroundRect;
    SDL_Rect m_textRect;

private:

    void setupBackground();
    void setupText();
    bool contains(float t_x, float t_y);

    void onHovered();
    void onUnhovered();
    void onClicked();
    void onUnclicked();

    Command * m_command;

    bool m_hovered;
    bool m_clicked;

    float m_hoveredSizeChange;
    float m_clickedSizeChange;

};

#endif // !BUTTON_H