#pragma once
#include <string>

class Entity
{
public:
	Entity() = default;
	virtual ~Entity() = default;
	virtual std::string serialize() const = 0;
	virtual size_t deserialize(const std::string& line) = 0;
};