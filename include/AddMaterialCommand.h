#ifndef ADD_MATERIAL_COMMAND_H
#define ADD_MATERIAL_COMMAND_H

#include <vector>
#include "Command.h"
#include "CounterButton.h"
#include "CommandHistory.h"

class AddMaterialCommand : public Command
{
public:

    AddMaterialCommand(CounterButton * t_counterButton, CommandHistory & t_commandHistory);
    virtual ~AddMaterialCommand() override;
    virtual void execute() override;
    virtual void undo() override;

private:

    CounterButton * m_counterButton;
    CommandHistory & m_commandHistory;

};

#endif // !ADD_MATERIAL_COMMAND_H