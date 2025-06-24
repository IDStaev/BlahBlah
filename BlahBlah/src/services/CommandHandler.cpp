#include <iostream>
#include "services/CommandHandler.h"

void CommandHandler::registerCommand(std::shared_ptr<Command> cmd)
{
	this->commands.push_back(cmd);
}

void CommandHandler::execute(const std::string& cmdName)
{
	for (const auto& command : this->commands) {
		if (command->name() == cmdName) {
			command->execute();
			return;
		}
	}
	std::cout << "Unknown command: " << cmdName << "\n";
}
