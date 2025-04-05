#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;
	unsigned int size() const;

private:
	T *_arr;
	unsigned int _size;
};

template <typename T>
Array<T>::Array()
{
	this->_arr = nullptr;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_arr = new T[n]();
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array &src)
{
	this->_size = src._size;
	this->_arr = new T[this->_size];

	for (unsigned int i = 0; i < this->_size; ++i)
	{
		this->_arr[i] = src._arr[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
	if (this == &rhs)
		return *this;

	delete[] this->_arr;
	this->_size = rhs._size;
	this->_arr = new T[this->_size];

	for (unsigned int index = 0; index < this->_size; ++index)
	{
		this->_arr[index] = rhs._arr[index];
	}

	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (this->_arr)
		delete[] this->_arr;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::out_of_range("Accessing out-of-bounds index in Array");

	return this->_arr[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw std::out_of_range("Accessing out-of-bounds index in Array (const)");

	return this->_arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}
