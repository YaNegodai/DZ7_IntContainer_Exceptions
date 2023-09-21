#pragma once
#include <iostream>
#include <stdexcept>

class bad_range : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "����� �� ������� �������";
	}
};

class bad_length : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "�������������� ������������ �����";
	}
};

class IntegerArray
{
public:
	//������������
	IntegerArray() = default;
	IntegerArray(size_t length);
	IntegerArray(const IntegerArray& original);

	//�����������
	~IntegerArray();
	

	//������
	IntegerArray& operator = (const IntegerArray& original);
	size_t getLength() const;
	void setLength(size_t newLength);
	void eraseArray();
	int& operator[](size_t index);
	void rangeCheck(size_t index);
	void lenghtCheck(size_t index);
	void ShowArray() const;
	void reallocate(size_t newLength);
	void resize(size_t newLength);
	void insertBefore(int value, size_t index);
	void remove(size_t index);
	void insertAtBegining(int value);
	void insertAtEnd(int value);
	void find(int value);

private:
	size_t _arrLength;
	int* _arrData{};
};