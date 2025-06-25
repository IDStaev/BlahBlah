#include "services/SessionManager.h"

SessionManager::~SessionManager()
{
    delete[] this->currentUser;
}

void SessionManager::login(const User& user)
{
    this->currentUser = user.clone();
}

void SessionManager::logout()
{
    delete[] this->currentUser;
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