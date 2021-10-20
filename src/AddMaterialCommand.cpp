#include "AddMaterialCommand.h"

AddMaterialCommand::AddMaterialCommand(CounterButton * t_counterButton, CommandHistory & t_commandHistory) :
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
    m_commandHistory.addCommand(this);
}

void AddMaterialCommand::undo()
{
    m_counterButton->decrementCounter();
}