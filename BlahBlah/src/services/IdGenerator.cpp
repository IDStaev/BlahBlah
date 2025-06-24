#include <fstream>
#include <filesystem>
#include "services/IdGenerator.h"

IdGenerator::IdGenerator()
	:filename("data/Id.bin")
{
	if (!fileExists())
		initializeFile();
}

uint32_t IdGenerator::getNew(EntityType type) const
{
	std::fstream ifs("data/Id.bin", std::ios::in | std::ios::out); // !!!
	if (!ifs.is_open())
		throw std::runtime_error("No " + this->filename + " file found");

	uint32_t id = 0;
	size_t offset = static_cast<size_t>(type);
	ifs.seekg(offset * sizeof(id), std::ios::beg);
	ifs.read(reinterpret_cast<char*>(&id), sizeof(id));
	++id;
	ifs.seekg(offset * sizeof(id), std::ios::beg);
	ifs.write(reinterpret_cast<const char*>(&id), sizeof(id));

	ifs.close();

	return id;
}

bool IdGenerator::fileExists() const
{
	if (std::filesystem::exists("data/Id.bin"));// !!!
	if (std::filesystem::is_regular_file(this->filename))
		return true;
	return false;
}

void IdGenerator::initializeFile() const
{
	std::ofstream out(this->filename, std::ios::binary);

	uint32_t value = 0;

	out.write(reinterpret_cast<const char*>(&value), sizeof(value));
	out.write(reinterpret_cast<const char*>(&value), sizeof(value));
	out.write(reinterpret_cast<const char*>(&value), sizeof(value));

	out.close();
}
