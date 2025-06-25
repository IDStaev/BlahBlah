#pragma once
#include <filesystem>
#include <vector>
#include "services\RepositoryTraits.hpp"

template<typename T>
class Repository {
public:
	Repository();

	void save(const T& obj) const;
	std::vector<T> loadAll() const;

private:
	std::string filename;

	void initializeFile() const;
	bool fileExists() const;
};

template<typename T>
Repository<T>::Repository()
	: filename(RepositoryTraits<T>::getFileName())
{
	if (!fileExists())
		initializeFile();
}

template<typename T>
void Repository<T>::save(const T& obj) const
{
	std::ofstream ofs(this->filename, std::ios::app);
	if (!ofs.is_open())
		throw std::runtime_error("No " + this->filename + " file found.");

	ofs << obj.serialize() << "\n";
	ofs.close();
}

template<typename T>
std::vector<T> Repository<T>::loadAll() const
{
	std::ifstream ifs(this->filename);
	if (!ifs.is_open())
		throw std::runtime_error("No " + this->filename + " file found.");

	std::vector<T> allEntries; // initial capacity

	std::string line;

	while (std::getline(ifs, line)) {
		if (line.empty()) continue;
		T entity;
		entity.deserialize(line);
		allEntries.push_back(entity);
	}

	return allEntries;
}

template<typename T>
void Repository<T>::initializeFile() const
{
	std::ofstream file(filename, std::ios::out | std::ios::trunc);
	file.close();
}

template<typename T>
bool Repository<T>::fileExists() const
{
	if (std::filesystem::exists(this->filename))
		if (std::filesystem::is_regular_file(this->filename))
			return true;
	return false;
}