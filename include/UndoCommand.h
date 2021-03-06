#ifndef UNDO_COMMAND_H
#define UNDO_COMMAND_H

#include <vector>
#include "Command.h"
#include "CommandHistory.h"

class UndoCommand : public Command
{
public:

    UndoCommand(CommandHistory & t_commandHistory);
    virtual ~UndoCommand();
    virtual void execute() override;
    virtual void undo() override;

private:

    CommandHistory & m_commandHistory;

};

#endif // !UNDO_COMMAND_H