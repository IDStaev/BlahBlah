#pragma once
#include <string>
#include "enums\EntityType.h"

class IdGenerator
{
public:
	IdGenerator();
	uint32_t getNew(IdType type) const;

private:
	std::string filename = "data/id.bin";
	bool fileExists() const;
	void initializeFile() const;
};

