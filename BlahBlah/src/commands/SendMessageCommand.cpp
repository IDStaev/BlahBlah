#include <iostream>
#include "commands\SendMessageCommand.h"

void SendMessageCommand::execute()
{
    if (!this->context.session.isLoggedIn()) {
        std::cout << "You must be logged in to send a message.\n";
        return;
    }

    std::string recipient, content;
    std::cin >> recipient;
    std::cin >> std::ws;
    std::getline(std::cin, content);

    std::vector<User> allUsers = this->context.userRepo.loadAll(); // maybe pointer
    std::vector<AdminUser> allAdmins = this->context.adminRepo.loadAll();
    for (const auto& user : allUsers) {
        if (user.getUsername() == recipient && this->context.session.getCurrentUser()->getUsername()!=recipient) {
            uint32_t id = this->context.idGenerator.getNew(IdType::Message);
            Message message(id, content, this->context.session.getCurrentUser()->getUsername(), recipient);
            this->context.messageRepo.save(message);
            std::cout << "Message sent successfully.\n";
            return;
        }
    }
    for (const auto& admin : allAdmins) {
        if (admin.getUsername() == recipient && this->context.session.getCurrentUser()->getUsername() != recipient) {
            uint32_t id = this->context.idGenerator.getNew(IdType::Message);
            Message message(id, content, this->context.session.getCurrentUser()->getUsername(), recipient);
            this->context.messageRepo.save(message);
            std::cout << "Message sent successfully.\n";
            return;
        }
    }
    std::cout << "Message not sent.\n";
}

std::string SendMessageCommand::name() const
{
    return "send_message";
}

bool SendMessageCommand::isAllowedForUser() const
{
    return true;
}

bool SendMessageCommand::isAllowedForAdmin() const
{
    return true;
}
