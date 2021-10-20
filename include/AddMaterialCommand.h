#ifndef ADD_MATERIAL_COMMAND_H
#define ADD_MATERIAL_COMMAND_H

#include <vector>
#include "Command.h"
#include "CounterButton.h"
#include "CommandHistory.h"
#include "brick/BrickFactory.h"

class AddMaterialCommand : public Command
{
public:

    AddMaterialCommand(CounterButton * t_counterButton, 
                       CommandHistory & t_commandHistory, 
                       std::vector<BrickFactory *> & t_factoryOrders,
                       BrickFactory * t_factory);

    virtual ~AddMaterialCommand() override;
    virtual void execute() override;
    virtual void undo() override;

private:

    CounterButton * m_counterButton;
    CommandHistory & m_commandHistory;
    std::vector<BrickFactory *> & m_factoryOrders;
    BrickFactory * m_factory;

};

#endif // !ADD_MATERIAL_COMMAND_H