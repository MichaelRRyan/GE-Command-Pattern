#ifndef REDO_COMMAND_H
#define REDO_COMMAND_H

#include <vector>
#include "Command.h"
#include "CommandHistory.h"

class RedoCommand : public Command
{
public:

    RedoCommand(CommandHistory & t_commandHistory);
    virtual ~RedoCommand();
    virtual void execute() override;
    virtual void undo() override;

private:

    CommandHistory & m_commandHistory;

};

#endif // !REDO_COMMAND_H