#include "AddMaterialCommand.h"

AddMaterialCommand::AddMaterialCommand(CounterButton * t_counterButton, 
                       CommandHistory & t_commandHistory, 
                       std::vector<BrickFactory *> & t_factoryOrders,
                       BrickFactory * t_factory) :
    m_counterButton{ t_counterButton },
    m_commandHistory{ t_commandHistory },
    m_factoryOrders{ t_factoryOrders },
    m_factory{ t_factory }
{

}

AddMaterialCommand::~AddMaterialCommand()
{
    if (m_factory) delete m_factory;
}

void AddMaterialCommand::execute()
{
    m_factoryOrders.push_back(m_factory);
    m_counterButton->incrementCounter();
    m_commandHistory.addCommand(this);
}

void AddMaterialCommand::undo()
{
    m_factoryOrders.pop_back();
    m_counterButton->decrementCounter();
}