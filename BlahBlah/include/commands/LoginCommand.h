#pragma once
#include "commands\Command.h"
class LoginCommand : public Command
{
public:
	LoginCommand(CommandContext context) : Command(context) {}
	void execute() override;
	std::string name() const override;
	bool isAllowedForUser() const override;
	bool isAllowedForAdmin() const override;
};

