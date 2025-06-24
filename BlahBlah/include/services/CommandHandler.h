#pragma once
#include <memory>
#include <vector>
#include "commands\Command.h"

class CommandHandler
{
public:
    void registerCommand(std::shared_ptr<Command> cmd); // UNIQUE?
    void execute(const std::string& cmdName);

private:
    std::vector<std::shared_ptr<Command>> commands;
};
