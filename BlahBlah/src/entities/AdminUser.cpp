#include "entities/AdminUser.h"
#include "commands/Command.h"

AdminUser::AdminUser(uint32_t id, const std::string& username, const std::string& passwordHash)
	:User(username, passwordHash)
{
}

uint32_t AdminUser::getId() const
{
	return this->id;
}

bool AdminUser::canExecute(const Command& cmd) const
{
	return cmd.isAllowedForAdmin();
}

std::string AdminUser::serialize() const
{
	std::string line = User::serialize() + " " + std::to_string(this->id);
	return line;
}

size_t AdminUser::deserialize(const std::string& line)
{
	size_t pos2 = User::deserialize(line);
	size_t pos3 = line.find(" ", pos2 + 1);

	this->id = std::stoul(line.substr(pos3 + 1, pos3 - pos2 - 1));

	return pos3;
}
