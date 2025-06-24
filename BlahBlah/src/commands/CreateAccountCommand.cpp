#include <iostream>
#include "commands/CreateAccountCommand.h"
#include "utils/sha256.h"

void CreateAccountCommand::execute()
{
    const User* currentUser = this->context.session.getCurrentUser();

    if (currentUser == nullptr && currentUser->canExecute(*this)) {
        std::string username, password;
        std::cin >> username >> password;

        User user(username, sha256(password));
        this->context.userRepo.save(user);

        std::cout << "Account created successfully.\n";
    }
    else {
        std::cout << "You must be logged out.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string CreateAccountCommand::name() const
{
    return "create_account";
}

bool CreateAccountCommand::isAllowedForUser() const
{
    return true;
}

bool CreateAccountCommand::isAllowedForAdmin() const
{
    return true;
}
