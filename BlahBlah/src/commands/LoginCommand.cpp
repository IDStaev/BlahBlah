#include <iostream>
#include "commands\LoginCommand.h"
#include "utils\sha256.h"

void LoginCommand::execute()
{
    if (this->context.session.isLoggedIn()) {
        std::cout << "You must be logged out.\n";
        return;
    }

    std::string username, password;
    std::cin >> username >> password;

    std::vector<User> allUsers = this->context.userRepo.loadAll(); // !!!maybe pointer
    std::vector<AdminUser> allAdmins = this->context.adminRepo.loadAll();

    for (const auto& user : allUsers) {
        if (user.getUsername() == username) {
            if (user.checkPassword(sha256(password))) {
                this->context.session.login(user);
                std::cout << "Successfully logged in.\n";
                return;
            }
        }
    }

    for (const auto& admin : allAdmins) {
        if (admin.getUsername() == username) {
            if (admin.checkPassword(sha256(password))) {
                this->context.session.login(admin);
                std::cout << "Successfully logged in.\n";
                return;
            }
        }
    }

    std::cout << "Invalid credentials.\n";
}

std::string LoginCommand::name() const
{
    return "login";
}

bool LoginCommand::isAllowedForUser() const
{
    return true;
}

bool LoginCommand::isAllowedForAdmin() const
{
    return true;
}
