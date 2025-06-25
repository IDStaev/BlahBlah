#include <iostream>
#include "commands\LogoutCommand.h"

void LogoutCommand::execute()
{
    if (!this->context.session.isLoggedIn()) {
        std::cout << "You must first be logged in.\n";
        return;
    }

    this->context.session.logout();
    std::cout << "Successfully logged out.\n";
}

std::string LogoutCommand::name() const
{
    return "logout";
}

bool LogoutCommand::isAllowedForUser() const
{
    return true;
}

bool LogoutCommand::isAllowedForAdmin() const
{
    return true;
}
