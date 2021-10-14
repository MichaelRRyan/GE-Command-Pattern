#include "UndoCommand.h"

UndoCommand::UndoCommand(std::vector<Command *> t_commandHistory, std::vector<Command *> t_undoneCommands) :
    m_commandHistory{ t_commandHistory },
    m_undoneCommands{ t_undoneCommands }
{

}

UndoCommand::~UndoCommand()
{

}

void UndoCommand::execute()
{
    Command * cmd = m_commandHistory.back();
    cmd->undo();
    m_commandHistory.pop_back();
    m_undoneCommands.push_back(cmd);
}

void UndoCommand::undo()
{
    
}