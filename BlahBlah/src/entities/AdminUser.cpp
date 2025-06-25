#include <iostream>
#include "entities/AdminUser.h"
#include "commands/Command.h"

AdminUser::AdminUser(uint32_t id, const std::string& username, const std::string& passwordHash)
	:User(username, passwordHash), id(id)
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
	size_t endpos = line.find(" ", pos2 + 1);
	if (endpos == std::string::npos)
		endpos = line.length();

	this->id = std::stoul(line.substr(pos2 + 1));

	return endpos;
}

void AdminUser::print() const
{
	std::cout << this->getUsername() << " {Admin} {id:" << this->id << "}\n";
}

User* AdminUser::clone() const
{
	return new AdminUser(*this);
}
