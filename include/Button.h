#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class Button
{
public:

    Button(SDL_Renderer* t_renderer, TTF_Font* t_font, std::string t_name, float t_x, float t_y);
    ~Button();
    void draw();

private:

    void setupBackground();
    void setupText();

    std::string m_name;

    float m_x;
    float m_y;

    SDL_Renderer * m_renderer;

    TTF_Font * m_font;

    SDL_Texture * m_background;
    SDL_Texture * m_text;

    SDL_Rect m_backgroundRect;
    SDL_Rect m_textRect;

};

#endif // !BUTTON_H