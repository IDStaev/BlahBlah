#pragma once
#include "entities\User.h"

class SessionManager
{
public:
	void login(const User& user);
	void logout();
	bool isLoggedIn() const;
	const User* getCurrentUser(); // const???

private:
	User* currentUser = nullptr;
};

