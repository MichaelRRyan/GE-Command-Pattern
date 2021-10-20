#ifndef COMMAND_HISTORY_H
#define COMMAND_HISTORY_H

#include <vector>
#include "Command.h"

class CommandHistory
{
public:

    CommandHistory();
    ~CommandHistory();

    void addCommand(Command * t_command);

    void undoCommand();
    void redoCommand();

private:

    std::vector<Command *> m_commandHistory;
    std::vector<Command *> m_undoneCommands;

    bool m_executingCommand;

};

#endif // !COMMAND_HISTORY_H