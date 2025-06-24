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
    size_t pos2 = line.find(" ", pos1 + 1);

    this->username = line.substr(0, pos1);
    this->passwordHash = line.substr(pos1 + 1, pos2 - pos1 - 1);

    return pos2;
}

