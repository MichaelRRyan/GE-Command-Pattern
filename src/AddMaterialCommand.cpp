#include "AddMaterialCommand.h"

AddMaterialCommand::AddMaterialCommand(CounterButton * t_counterButton) :
    m_counterButton{ t_counterButton }
{

}

AddMaterialCommand::~AddMaterialCommand()
{

}

void AddMaterialCommand::execute()
{
    m_counterButton->incrementCounter();
}

void AddMaterialCommand::undo()
{
    m_counterButton->decrementCounter();
}