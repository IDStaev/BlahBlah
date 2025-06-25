#include <iostream>
#include "commands\SelectChatCommand.h"

void SelectChatCommand::execute()
{
    if (!this->context.session.isLoggedIn()) {
        std::cout << "You must be logged in to select a chat.\n";
        return;
    }

    std::string username;
    std::cin >> username;

    std::vector<Message> messages = this->context.messageRepo.loadAll();
    std::vector<Message> currentUserMessages;
    for (const auto& message : messages) {
        if ((message.getSender() == this->context.session.getCurrentUser()->getUsername() &&
            message.getRecipient() == username) ||
            (message.getSender() == username &&
                message.getRecipient() == this->context.session.getCurrentUser()->getUsername()))
            currentUserMessages.push_back(message);
    }

    if (currentUserMessages.size() == 0) {
        std::cout << "No messages.\n";
        return;
    }

    for (const auto& message : currentUserMessages) {
        message.print();
    }

}

std::string SelectChatCommand::name() const
{
    return "select_chat";
}

bool SelectChatCommand::isAllowedForUser() const
{
    return true;
}

bool SelectChatCommand::isAllowedForAdmin() const
{
    return true;
}
