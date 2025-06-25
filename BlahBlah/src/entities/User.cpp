#include <iostream>
#include "entities/User.h"
#include "commands/Command.h"

User::User(const std::string& username, const std::string& passwordHash)
    :username(username), passwordHash(passwordHash)
{
}

std::string User::getUsername() const
{
    return this->username;
}

bool User::checkPassword(const std::string& passwordHash) const
{
    return (this->passwordHash == passwordHash);
}

bool User::canExecute(const Command& cmd) const
{
    return cmd.isAllowedForUser();
}

std::string User::serialize() const
{
    std::string line = this->username + " " + this->passwordHash;
    return line;
}

size_t User::deserialize(const std::string& line)
{
    size_t pos1 = line.find(" ");
    size_t endpos = line.find(" ", pos1 + 1);
    if (endpos == std::string::npos)
        endpos = line.length();
    this->username = line.substr(0, pos1);
    this->passwordHash = line.substr(pos1 + 1, endpos - pos1 - 1);

    return endpos;
}

void User::print() const
{
    std::cout << this->username << " {User}\n";
}

User* User::clone() const
{
    return new User(*this);
}
