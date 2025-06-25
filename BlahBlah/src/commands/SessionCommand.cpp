#include <iostream>
#include "commands\SessionCommand.h"

void SessionCommand::execute()
{
    if (!this->context.session.isLoggedIn()) {
        std::cout << "Not logged in.\n";
        return;
    }

    const User* currentUser = this->context.session.getCurrentUser();
    std::cout << "Currently logged in as: ";
    currentUser->print();
}

std::string SessionCommand::name() const
{
    return "session";
}

bool SessionCommand::isAllowedForUser() const
{
    return true;
}

bool SessionCommand::isAllowedForAdmin() const
{
    return true;
}
