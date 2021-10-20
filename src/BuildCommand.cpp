#include "BuildCommand.h"
#include <iostream>

BuildCommand::BuildCommand(std::vector<BrickFactory *> & t_factoryOrders) :
    m_factoryOrders{ t_factoryOrders }
{

}

BuildCommand::~BuildCommand()
{

}

void BuildCommand::execute()
{
    std::cout << "--- Building bricks ---" << std::endl;

    std::vector<Brick *> m_bricks;

    for (BrickFactory * factory : m_factoryOrders)
        m_bricks.push_back(factory->getBricks(1).at(0));

    for (Brick * brick : m_bricks)
    {
        brick->render();
        delete brick;
    }
}

void BuildCommand::undo()
{

}