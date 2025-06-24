#include "services/SessionManager.h"

void SessionManager::login(const User& user)
{
    this->currentUser = new User(user);
}

void SessionManager::logout()
{
    this->currentUser = nullptr;
}

bool SessionManager::isLoggedIn() const
{
    return (this->currentUser != nullptr);
}

const User* SessionManager::getCurrentUser()
{
    return this->currentUser;
}