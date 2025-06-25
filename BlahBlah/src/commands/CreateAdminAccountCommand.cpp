#include <iostream>
#include "commands\CreateAdminAccountCommand.h"
#include "utils/sha256.h"

void CreateAdminAccountCommand::execute()
{
    if (this->context.session.isLoggedIn()) {
        std::cout << "You must be logged out.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::string username, password;
    std::cin >> username >> password;

    // DRY PRINCIPLE FAIL
    std::vector<User> allUsers = this->context.userRepo.loadAll(); // maybe pointer
    std::vector<AdminUser> allAdmins = this->context.adminRepo.loadAll();
    for (const auto& user : allUsers) {
        if (user.getUsername() == username) {
            std::cout << "User with username {" << username << "} already exists.\n";
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

    uint32_t id = this->context.idGenerator.getNew(IdType::Admin);

    AdminUser admin(id, username, sha256(password));
    this->context.adminRepo.save(admin);

    std::cout << "Account created successfully.\n";
}

std::string CreateAdminAccountCommand::name() const
{
    return "create_admin_account";
}

bool CreateAdminAccountCommand::isAllowedForUser() const
{
    return true;
}

bool CreateAdminAccountCommand::isAllowedForAdmin() const
{
    return true;
}
