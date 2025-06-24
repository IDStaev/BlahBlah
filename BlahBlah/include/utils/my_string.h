#pragma once
#include <iostream>

class my_string
{
public:
	my_string();
	my_string(const char* str);

	my_string(const my_string& other);
	my_string(my_string&& other) noexcept;

	my_string& operator=(const my_string& other);
	my_string& operator=(my_string&& other) noexcept;

	~my_string();

	size_t length() const;
	const char* c_str() const;

	my_string& operator+=(const my_string& other);

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	friend std::ostream& operator<<(std::ostream& stream, const my_string& str);
	friend std::istream& operator>>(std::istream& stream, my_string& str);

private:
	char* data = nullptr;

	void resize(size_t newCapacity);
	void copyString(const char* str);
	void copyDynamicMemory(const my_string& other);
	void moveDynamicMemory(my_string&& other);
	void freeDynamicMemory();
};

std::ostream& operator<<(std::ostream& stream, const my_string& str);
std::istream& operator>>(std::istream& stream, my_string& str);
bool operator==(const my_string& lhs, const my_string& rhs);
bool operator!=(const my_string& lhs, const my_string& rhs);