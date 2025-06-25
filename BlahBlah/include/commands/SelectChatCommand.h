#pragma once
#include "commands\Command.h"

class SelectChatCommand : public Command
{
public:
	SelectChatCommand(CommandContext context) : Command(context) {}
	void execute() override;
	std::string name() const override;
	bool isAllowedForUser() const override;
	bool isAllowedForAdmin() const override;
};

