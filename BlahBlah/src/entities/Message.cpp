#include <iostream>
#include <iomanip>
#include <sstream>
#include "entities\Message.h"

Message::Message()
{
    this->time = std::chrono::system_clock::now();
}

Message::Message(uint32_t id, std::string content, std::string sender, std::string recipient)
    : id(id), content(content), sender(sender), recipient(recipient)
{
    this->time = std::chrono::system_clock::now();
}

std::string Message::serialize() const
{
    unsigned long long ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        this->time.time_since_epoch()).count();

    std::string line = std::to_string(this->id) + "|" +
        this->sender + "|" +
        this->recipient + "|" +
        std::to_string(ms) + "|" +
        this->content;

    return line;
}

size_t Message::deserialize(const std::string& line)
{
    size_t pos1 = line.find("|");
    size_t pos2 = line.find("|", pos1 + 1);
    size_t pos3 = line.find("|", pos2 + 1);
    size_t pos4 = line.find("|", pos3 + 1);

    this->id = std::stoul(line.substr(0, pos1));
    this->sender = line.substr(pos1 + 1, pos2 - pos1 - 1);
    this->recipient = line.substr(pos2 + 1, pos3 - pos2 - 1);
    std::string msStr = line.substr(pos3 + 1, pos4 - pos3 - 1);
    unsigned long long ms = std::stoull(msStr);
    this->time = std::chrono::system_clock::time_point{ std::chrono::milliseconds(ms) };
    this->content = line.substr(pos4 + 1);

    return pos4;
}

std::string Message::getSender() const
{
    return this->sender;
}

std::string Message::getRecipient() const
{
    return this->recipient;
}

void Message::print() const
{
    std::cout << "[" << formatTimePoint(this->time) << "] ";
    std::cout << this->getSender() << ": ";
    std::cout << this->content << std::endl;
}

std::string Message::formatTimePoint(std::chrono::system_clock::time_point tp) const {
    std::time_t time = std::chrono::system_clock::to_time_t(tp);

    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &time);  // Windows
#else
    localtime_r(&time, &tm);  // Linux/macOS
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
