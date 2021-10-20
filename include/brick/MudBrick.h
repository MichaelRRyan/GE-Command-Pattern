#ifndef MUD_BRICK_H
#define MUD_BRICK_H

#include <iostream>
#include "Brick.h"

class MudBrick : public Brick
{
public:
    MudBrick() { }
    void render() { std::cout << "Drawing a Mud Brick at location" << this << std::endl; }
};

#endif // !MUD_BRICK_H