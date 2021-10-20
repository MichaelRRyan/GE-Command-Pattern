#ifndef MUD_BRICK_H
#define MUD_BRICK_H

#include <iostream>
#include "Brick.h"

class MudBrick : public Brick
{
public:
    MudBrick() { }
    void render() { std::cout << "Splat! - Mud Brick @ " << this << std::endl; }
};

#endif // !MUD_BRICK_H