#include "RedoCommand.h"

RedoCommand::RedoCommand(CommandHistory & t_commandHistory) :
    m_commandHistory{ t_commandHistory }
{

}

RedoCommand::~RedoCommand()
{

}

void RedoCommand::execute()
{
    m_commandHistory.redoCommand();
}

void RedoCommand::undo()
{
    m_commandHistory.undoCommand();
}