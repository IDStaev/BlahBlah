#include <iostream>
#include "commands/CreateAccountCommand.h"
#include "utils/sha256.h"

void CreateAccountCommand::execute()
{
    if (this->context.session.isLoggedIn()) {
        std::cout << "You must be logged out.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    
    std::string username, password; // Check between fields
    std::cin >> username >> password;

    std::vector<User> allUsers = this->context.userRepo.loadAll(); // maybe pointer
    std::vector<AdminUser> allAdmins = this->context.adminRepo.loadAll();
    for (const auto& user : allUsers) {
        if (user.getUsername() == username) {
            std::cout << "User with username {" << username<<"} already exists.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
    }
    for (const auto& admin : allAdmins) {
        if (admin.getUsername() == username) {
            std::cout << "User with username {" << username << "} already exists.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
    }

    User user(username, sha256(password));
    this->context.userRepo.save(user);

    std::cout << "Account created successfully.\n";
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
