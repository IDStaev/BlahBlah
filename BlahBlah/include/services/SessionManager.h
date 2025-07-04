#pragma once
#include "entities\User.h"

class SessionManager
{
public:
	~SessionManager();
	void login(const User& user);
	void logout();
	bool isLoggedIn() const;
	const User* getCurrentUser();

private:
	User* currentUser = nullptr;
};

