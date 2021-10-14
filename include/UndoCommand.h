#ifndef UNDO_COMMAND_H
#define UNDO_COMMAND_H

#include <vector>
#include "Command.h"

class UndoCommand : public Command
{
public:

    UndoCommand(std::vector<Command *> t_commandHistory, std::vector<Command *> t_undoneCommands);
    virtual ~UndoCommand();
    virtual void execute() override;
    virtual void undo() override;

private:

    std::vector<Command *> m_commandHistory;
    std::vector<Command *> m_undoneCommands;

};

#endif // !UNDO_COMMAND_H