#ifndef ADD_MATERIAL_COMMAND_H
#define ADD_MATERIAL_COMMAND_H

#include "Command.h"
#include "CounterButton.h"

class AddMaterialCommand : public Command
{
public:

    AddMaterialCommand(CounterButton * t_counterButton);
    virtual ~AddMaterialCommand() override;
    virtual void execute() override;
    virtual void undo() override;

private:

    CounterButton * m_counterButton;

};

#endif // !ADD_MATERIAL_COMMAND_H