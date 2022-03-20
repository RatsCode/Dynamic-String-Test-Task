#pragma once



class DynamicString
{
public:
	DynamicString();
	DynamicString(const char* arr);
	DynamicString(const DynamicString& other);
	DynamicString(DynamicString&& other) noexcept;
	~DynamicString();

	DynamicString& operator=(const char* arr);
	DynamicString& operator=(const DynamicString& other);
	DynamicString& operator=(DynamicString&& other) noexcept;

	char* get_array() { return _array; };

	void clear();

private:

	char*	_array;
	size_t	_size;

	friend DynamicString operator+(const char* first,			const DynamicString& second);
	friend DynamicString operator+(const DynamicString& first,	const char* second);
	friend DynamicString operator+(const DynamicString& first,	const DynamicString& second);

	friend bool operator>(const DynamicString& lhs, const DynamicString& rhs);
};
