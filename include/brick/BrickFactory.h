#ifndef BRICK_FACTORY_H
#define BRICK_FACTORY_H

#include <vector>
#include "Brick.h"

class BrickFactory
{
public:
    BrickFactory() { }
    virtual ~BrickFactory() { }
    virtual std::vector<Brick *> getBricks(int t_numberOfBricks) = 0;
};

#endif // !BRICK_FACTORY_H