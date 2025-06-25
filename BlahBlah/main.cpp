#include <iostream>
#include "entities\AdminUser.h"
#include "services\CommandHandler.h"
#include "commands\CreateAccountCommand.h"
#include "commands\CreateAdminAccountCommand.h"
#include "commands\SessionCommand.h"
#include "commands\LoginCommand.h"
#include "commands\LogoutCommand.h"
// FIX

// README: include + C++17
int main() {
	SessionManager session;
	Repository<User> userRepo;
	Repository<AdminUser> adminRepo;
	IdGenerator idGenerator;

	CommandContext context{ session, userRepo, adminRepo, idGenerator };

	CommandHandler handler;
	handler.registerCommand(std::make_shared<CreateAccountCommand>(context));
	handler.registerCommand(std::make_shared<CreateAdminAccountCommand>(context));
	handler.registerCommand(std::make_shared<SessionCommand>(context));
	handler.registerCommand(std::make_shared<LoginCommand>(context));
	handler.registerCommand(std::make_shared<LogoutCommand>(context));

	// better UI
	// Validation
	std::string input;
	while (true) {
		std::cout << "> ";
		std::cin >> input;
		if (input == "exit")
			break;
		handler.execute(input);
	}
}

