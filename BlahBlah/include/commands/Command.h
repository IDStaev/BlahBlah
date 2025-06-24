#pragma once
#include <string>
#include "services\CommandContext.h"

class Command
{
public:
	Command(CommandContext context); // By reference?
	virtual void execute() = 0;
	virtual std::string name() const = 0;
	virtual bool isAllowedForUser() const = 0;
	virtual bool isAllowedForAdmin() const = 0;
	virtual ~Command() = default;
protected:
	CommandContext context;
};

