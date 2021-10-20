#ifndef COUNTER_BUTTON_H
#define COUNTER_BUTTON_H

#include "Button.h"

class CounterButton : public Button
{
public:

    CounterButton(SDL_Renderer* t_renderer, TTF_Font* t_font, std::string t_name, float t_x, float t_y);
    virtual ~CounterButton() override;
    virtual void draw() override;

    void incrementCounter();
    void decrementCounter();

protected:

    virtual void onHovered() override;
    virtual void onUnhovered() override;
    virtual void onClicked() override;
    virtual void onUnclicked() override;

private:

    void setupCounterText(int t_count);

    SDL_Texture * m_counterText;
    SDL_Rect m_counterTextRect;

    int m_count;

};

#endif // !COUNTER_BUTTON_H