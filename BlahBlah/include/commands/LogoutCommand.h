#pragma once
#include "commands\Command.h"

class LogoutCommand : public Command
{
public:
	LogoutCommand(CommandContext context) : Command(context) {}
	void execute() override;
	std::string name() const override;
	bool isAllowedForUser() const override;
	bool isAllowedForAdmin() const override;
};

