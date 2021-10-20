#ifndef CLAY_BRICK_FACTORY_H
#define CLAY_BRICK_FACTORY_H

#include <iostream>
#include <vector>
#include "BrickFactory.h"
#include "ClayBrick.h"

class ClayBrickFactory : public BrickFactory
{
public:
    ClayBrickFactory() { }

    std::vector<Brick *> getBricks(int t_numberOfBricks)
    {
        std::vector<Brick *> bricks;

        std::cout << "Building " << t_numberOfBricks 
            << " clay brick(s) from the factory @ " << this << std::endl;
        
        for (int i = 0; i < t_numberOfBricks; i++)
            bricks.push_back(new ClayBrick());

        return bricks;
    }
};

#endif // !CLAY_BRICK_FACTORY_H