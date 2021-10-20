#ifndef MUD_BRICK_FACTORY_H
#define MUD_BRICK_FACTORY_H

#include <vector>
#include <iostream>
#include "BrickFactory.h"
#include "MudBrick.h"

class MudBrickFactory : public BrickFactory
{
public:
    MudBrickFactory() { }

    std::vector<Brick *> getBricks(int t_numberOfBricks)
    {
        std::vector<Brick *> bricks;

        std::cout << "Building " << t_numberOfBricks 
            << " mud brick(s) from the factory at location " << this << std::endl;

        for (int i = 0; i < t_numberOfBricks; i++)
            bricks.push_back(new MudBrick());

        return bricks;
    }
};

#endif // !MUD_BRICK_FACTORY_H