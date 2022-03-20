#include "DynamicString.h"



DynamicString::DynamicString()
	:
	_size(0),
	_array(nullptr)
{}

DynamicString::DynamicString(const char* arr)
	:
	_size(0)

{
	while (arr[_size] != '\0') { ++_size; };

	_array = new char[++_size];
	for (size_t i = 0; i < _size; ++i)
	{
		_array[i] = arr[i];
	}
}

DynamicString::DynamicString(const DynamicString& other)
	:
	_size(other._size)

{
	_array = new char[_size];

	for (size_t i = 0; i < _size; ++i)
	{
		_array[i] = other._array[i];
	}
}

DynamicString::DynamicString(DynamicString&& other) noexcept
	:
	_size(other._size),
	_array(other._array)

{
	other._array = nullptr;
}

DynamicString::~DynamicString()
{
	delete[] _array;
}

DynamicString& DynamicString::operator=(const char* arr)
{
	clear();

	while (arr[_size] != '\0') { ++_size; };

	_array = new char[++_size];
	for (size_t i = 0; i < _size; ++i)
	{
		_array[i] = arr[i];
	}

	return *this;
}

DynamicString& DynamicString::operator=(const DynamicString& other)
{
	delete[] _array;

	_size = other._size;

	_array = new char[_size];
	for (size_t i = 0; i < _size; ++i)
	{
		_array[i] = other._array[i];
	}

	return *this;
}

DynamicString& DynamicString::operator=(DynamicString&& other) noexcept
{
	delete[] _array;

	_size = other._size;

	_array = other._array;
	other._array = nullptr;

	return *this;
}

void DynamicString::clear()
{
	delete[] _array;
	_array = nullptr;
	_size = 0;
}

DynamicString operator+(const char* first, const DynamicString& second)
{
	DynamicString res;
	size_t first_size = 0;

	while (first[first_size] != '\0') { ++first_size; };

	res._array = new char[(res._size = first_size + second._size)];

	for (size_t i = 0; i < first_size; ++i)
	{
		res._array[i] = first[i];
	}
	for (size_t i = 0; i < second._size; ++i)
	{
		res._array[first_size + i] = second._array[i];
	}

	return res;
}

DynamicString operator+(const DynamicString& first, const char* second)
{
	DynamicString res;

	while (second[res._size] != '\0') { ++res._size; };

	res._array = new char[(res._size += first._size)];
	for (size_t i = 0; i < first._size; ++i)
	{
		res._array[i] = first._array[i];
	}
	for (size_t i = 0; second[i] != '\0'; ++i)
	{
		res._array[first._size + i] = second[i];
	}

	return res;
}

DynamicString operator+(const DynamicString& first, const DynamicString& second)
{
	DynamicString res;

	res._size = first._size + second._size;
	res._array = new char[res._size];

	for (size_t i = 0; i < first._size; ++i)
	{
		res._array[i] = first._array[i];
	}
	for (size_t i = 0; i < second._size; ++i)
	{
		res._array[first._size + i] = second._array[i];
	}

	return res;
}

//bool operator>(const DynamicString& lhs, const DynamicString& rhs)
//{
//	for (size_t i = 0; i < lhs._size && i < rhs._size + 1; ++i)
//	{
//		if (lhs._array[i] > rhs._array[i])
//		{
//			return true;
//		}
//		else if (lhs._array[i] < rhs._array[i])
//		{
//			return false;
//		}
//	}
//
//	return false;
//}

bool operator>(const DynamicString& lhs, const DynamicString& rhs)
{
	for (size_t i = 0; i < lhs._size && i < rhs._size + 1; ++i)
	{
		if (	lhs._array[i] - rhs._array[i] == 0 
			||	lhs._array[i] - rhs._array[i] == 32 
			||	lhs._array[i] - rhs._array[i] == -32) // if first char == second char (case insensitive)
		{
			continue;
		}
		else if (lhs._array[i] - rhs._array[i] > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}