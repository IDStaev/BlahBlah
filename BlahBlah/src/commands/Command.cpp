#include "commands\Command.h"

Command::Command(CommandContext context)
	: context(context)
{ }

bool Command::isAllowedForUser() const
{
	return false;
}

bool Command::isAllowedForAdmin() const
{
	return false;
}
