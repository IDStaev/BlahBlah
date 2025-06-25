#pragma once
#include <string>
#include "entities\Entity.h"

class Command;

class User : public Entity
{
public:
	User() = default;
	User(const std::string& username, const std::string& passwordHash);

	std::string getUsername() const;
	bool checkPassword(const std::string& passwordHash) const;

	virtual bool canExecute(const Command& cmd) const;
	std::string serialize() const override;
	size_t deserialize(const std::string& line) override;

	virtual void print() const;
	virtual User* clone() const;

private:
	std::string username = "";
	std::string passwordHash = "";
};