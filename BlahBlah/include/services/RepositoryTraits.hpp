#pragma once
#include <string>
#include <fstream>
#include "entities\User.h"
#include "entities\AdminUser.h"

template<typename T>
struct RepositoryTraits {
	static std::string getFileName();
};

template<typename T>
std::string RepositoryTraits<T>::getFileName()
{
	return "";
}

template<>
struct RepositoryTraits<User> {
	static std::string getFileName();
};

inline std::string RepositoryTraits<User>::getFileName()
{
	return "data/users.txt";
}

template<>
struct RepositoryTraits<AdminUser> {
	static std::string getFileName();
};

inline std::string RepositoryTraits<AdminUser>::getFileName()
{
	return "data/admins.txt";
}