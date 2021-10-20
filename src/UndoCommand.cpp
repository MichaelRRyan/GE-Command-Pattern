#include "UndoCommand.h"

UndoCommand::UndoCommand(CommandHistory & t_commandHistory) :
    m_commandHistory{ t_commandHistory }
{

}

UndoCommand::~UndoCommand()
{

}

void UndoCommand::execute()
{
    m_commandHistory.undoCommand();
}

void UndoCommand::undo()
{
    m_commandHistory.redoCommand();
}