#pragma once
#include <string>
#include <fstream>
#include "entities\User.h"
#include "entities\AdminUser.h"

namespace FILENAME {
	static const char* DEFAULT = "";
	static const char* USER = "data/users.txt";
	static const char* ADMIN = "data/admins.txt";
}

template<typename T>
struct RepositoryTraits {
	static std::string getFileName();
};

template<typename T>
std::string RepositoryTraits<T>::getFileName()
{
	return FILENAME::DEFAULT;
}

template<>
struct RepositoryTraits<User> {
	static std::string getFileName();
};

inline std::string RepositoryTraits<User>::getFileName()
{
	return FILENAME::USER;
}

template<>
struct RepositoryTraits<AdminUser> {
	static std::string getFileName();
};

inline std::string RepositoryTraits<AdminUser>::getFileName()
{
	return FILENAME::ADMIN;
}