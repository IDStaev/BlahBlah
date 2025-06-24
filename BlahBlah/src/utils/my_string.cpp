#include "utils/my_string.h"

my_string::my_string() : my_string("")
{
}

my_string::my_string(const char* str)
{
	if (str == nullptr)
		throw std::invalid_argument("str cannot be a nullptr.");

	copyString(str);
}

my_string::my_string(const my_string& other)
{
	if (other.data == nullptr)
		throw std::invalid_argument("other.str cannot be a nullptr.");

	copyDynamicMemory(other);
}

my_string::my_string(my_string&& other) noexcept
{
	moveDynamicMemory(std::move(other));
}

my_string& my_string::operator=(const my_string& other)
{
	if (this != &other) {
		freeDynamicMemory();
		copyDynamicMemory(other);
	}
	return *this;
}

my_string& my_string::operator=(my_string&& other) noexcept
{
	if (this != &other) {
		freeDynamicMemory();
		moveDynamicMemory(std::move(other));
	}
	return *this;
}

my_string::~my_string()
{
	freeDynamicMemory();
}

size_t my_string::length() const
{
	return std::strlen(this->data);
}

const char* my_string::c_str() const
{
	return this->data;
}

my_string& my_string::operator+=(const my_string& other)
{
	size_t myLength = length();
	size_t otherLength = other.length();

	resize(myLength + otherLength + 1);
	for (int i = myLength; i < myLength + otherLength; i++)
		data[i] = other[i - myLength];
	data[myLength + otherLength] = '\0';
	return *this;
}

char& my_string::operator[](size_t index)
{
	if (index >= length())
		throw std::out_of_range("Index out of range.");

	return this->data[index];
}

const char& my_string::operator[](size_t index) const
{
	if (index >= length())
		throw std::out_of_range("Index out of range.");

	return this->data[index];
}

void my_string::resize(size_t newCapacity)
{
	char* newData = new char[newCapacity];
	for (int i = 0; i < length(); i++)
		newData[i] = this->data[i];
	newData[length()] = '\0';
	freeDynamicMemory();
	this->data = newData;
}

void my_string::copyString(const char* str)
{
	size_t size = std::strlen(str) + 1;
	this->data = new char[size];
	memcpy(this->data, str, size);
}

void my_string::copyDynamicMemory(const my_string& other)
{
	copyString(other.data);
}

void my_string::moveDynamicMemory(my_string&& other)
{
	this->data = other.data;
	other.data = nullptr;
}

void my_string::freeDynamicMemory()
{
	delete[] this->data;
	this->data = nullptr;
}

std::ostream& operator<<(std::ostream& stream, const my_string& str)
{
	if (str.c_str() != nullptr)
		stream << str.c_str();
	return stream;
}

std::istream& operator>>(std::istream& stream, my_string& str)
{
	char buff[2048];
	stream >> buff;
	size_t size = std::strlen(buff) + 1;
	str.freeDynamicMemory();
	str.data = new char[size];
	memcpy(str.data, buff, size);
	return stream;
}

bool operator==(const my_string& lhs, const my_string& rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) == 0);
}

bool operator!=(const my_string& lhs, const my_string& rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) != 0);
}
