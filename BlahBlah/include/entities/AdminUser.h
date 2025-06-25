#pragma once
#include "entities\User.h"

class AdminUser : public User
{
public:
	AdminUser() = default;
	AdminUser(uint32_t id, const std::string& username, const std::string& passwordHash);

	uint32_t getId() const;

	bool canExecute(const Command& cmd) const override;
	std::string serialize() const override;
	size_t deserialize(const std::string& line) override;

	void print() const override;
	User* clone() const override;

private:
	uint32_t id = 0;
};

