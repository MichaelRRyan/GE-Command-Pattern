#ifndef CLAY_BRICK_H
#define CLAY_BRICK_H

#include <iostream>
#include "Brick.h"

class ClayBrick : public Brick
{
public:
    ClayBrick() { }
    void render() { std::cout << "Drawing a Clay Brick at location" << this << std::endl; }
};

#endif // !CLAY_BRICK_H
