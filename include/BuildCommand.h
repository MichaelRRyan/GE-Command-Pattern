#ifndef BUILD_COMMAND_H
#define BUILD_COMMAND_H

#include <vector>
#include "Command.h"
#include "brick/BrickFactory.h"

class BuildCommand : public Command
{
public:
    BuildCommand(std::vector<BrickFactory *> & t_factoryOrders);
    virtual ~BuildCommand();
    virtual void execute() override;
    virtual void undo() override;
private:

    std::vector<BrickFactory *> & m_factoryOrders;

};

#endif // !BUILD_COMMAND_H