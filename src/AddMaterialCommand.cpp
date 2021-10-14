#include "AddMaterialCommand.h"

AddMaterialCommand::AddMaterialCommand(CounterButton * t_counterButton, std::vector<Command *> t_commandHistory) :
    m_counterButton{ t_counterButton },
    m_commandHistory{ t_commandHistory }
{

}

AddMaterialCommand::~AddMaterialCommand()
{

}

void AddMaterialCommand::execute()
{
    m_counterButton->incrementCounter();
    m_commandHistory.push_back(this);
}

void AddMaterialCommand::undo()
{
    m_counterButton->decrementCounter();
}