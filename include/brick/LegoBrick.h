#ifndef LEGO_BRICK_H
#define LEGO_BRICK_H

#include <iostream>
#include "Brick.h"

class LegoBrick : public Brick
{
public:
    LegoBrick() { }
    void render() { std::cout << "Click! - Lego Brick @ " << this << std::endl; }
};

#endif // !LEGO_BRICK_H