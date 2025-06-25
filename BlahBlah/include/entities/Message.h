#pragma once
#include <chrono>
#include "entities\Entity.h"

class Message : public Entity
{
public:
	Message();
	Message(uint32_t id, std::string content, std::string sender, std::string recipient);
	std::string serialize() const override;
	size_t deserialize(const std::string& line) override;

	std::string getSender() const;
	std::string getRecipient() const;
	void print() const;

private:
	uint32_t id = 0;
	std::string content = "";
	std::string sender = "";
	std::string recipient = "";
	std::chrono::system_clock::time_point time;
	// Is Read

	std::string formatTimePoint(std::chrono::system_clock::time_point tp) const;
};

