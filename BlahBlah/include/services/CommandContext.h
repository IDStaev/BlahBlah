#pragma once
#include "services\SessionManager.h"
#include "services\Repository.hpp"
#include "entities\AdminUser.h"
#include "entities\Message.h"
#include "services\IdGenerator.h"

//Expand + const correctness + struct maybe
struct CommandContext
{
	SessionManager& session;
	const Repository<User>& userRepo;
	const Repository<AdminUser>& adminRepo;
	const Repository<Message>& messageRepo;
	const IdGenerator& idGenerator;
};

