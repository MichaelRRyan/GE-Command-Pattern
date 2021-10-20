#include "CommandHistory.h"

CommandHistory::CommandHistory() :
    m_executingCommand{ false }
{

}

CommandHistory::~CommandHistory()
{

}

void CommandHistory::addCommand(Command * t_command)
{
    m_commandHistory.push_back(t_command);

    if (!m_executingCommand)
        m_undoneCommands.clear();
}

void CommandHistory::undoCommand()
{
    if (!m_commandHistory.empty())
    {
        Command * cmd = m_commandHistory.back();
        cmd->undo();
        m_commandHistory.pop_back();
        m_undoneCommands.push_back(cmd);
    }
}

void CommandHistory::redoCommand()
{
    if (!m_undoneCommands.empty())
    {
        Command * cmd = m_undoneCommands.back();
        m_executingCommand = true;
        cmd->execute();
        m_executingCommand = false;
        m_undoneCommands.pop_back();
    }
}