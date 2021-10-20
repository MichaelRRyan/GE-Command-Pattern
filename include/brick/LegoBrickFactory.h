#ifndef LEGO_BRICK_FACTORY_H
#define LEGO_BRICK_FACTORY_H

#include <iostream>
#include <vector>
#include "BrickFactory.h"
#include "LegoBrick.h"

class LegoBrickFactory : public BrickFactory
{
public:
    LegoBrickFactory() { }

    std::vector<Brick *> getBricks(int t_numberOfBricks)
    {
        std::vector<Brick *> bricks;
        
        std::cout << "Building " << t_numberOfBricks 
            << " Lego brick(s) from the factory at location " << this << std::endl;

        for (int i = 0; i < t_numberOfBricks; i++)
            bricks.push_back(new LegoBrick());

        return bricks;
    }
};

#endif // !LEGO_BRICK_FACTORY_H