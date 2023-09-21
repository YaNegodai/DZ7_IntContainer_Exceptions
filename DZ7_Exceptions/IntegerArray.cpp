#include "IntegerArray.h"

IntegerArray::IntegerArray(size_t length) : _arrLength(length)
{
	if (_arrLength <= 0)
		throw bad_length();
	_arrData = new int[_arrLength] {};
}

IntegerArray::IntegerArray(const IntegerArray& original)
{
	reallocate(original.getLength());
	for (int i{ 0 }; i < _arrLength; ++i)
		_arrData[i] = original._arrData[i];
}

IntegerArray::~IntegerArray()
{
	delete[] _arrData;
}

IntegerArray& IntegerArray::operator=(const IntegerArray& original)
{
	if (&original == this)
		return *this;
	reallocate(original.getLength());
	for (int i{ 0 }; i < _arrLength; ++i)
		_arrData[i] = original._arrData[i];

	return *this;
}

size_t IntegerArray::getLength() const
{
	return _arrLength;
}

void IntegerArray::setLength(size_t newLength)
{
	this->lenghtCheck(newLength);
	_arrLength = newLength;
}

void IntegerArray::eraseArray()
{
	delete[] _arrData;
	_arrData = nullptr;
	_arrLength = 0;
}

int& IntegerArray::operator[](size_t index)
{
	this->rangeCheck(index);
	return _arrData[index];
}

void IntegerArray::rangeCheck(size_t index)
{
	if (index < 0 || index > _arrLength)
		throw bad_range();
}

void IntegerArray::lenghtCheck(size_t index)
{
	if (index < 0 || index > _arrLength)
		throw bad_length();
}


void IntegerArray::ShowArray() const
{
	for (int i = 0; i < _arrLength; i++)
	{
		std::cout << "\nЭлемент " << i << ": " << _arrData[i];
	}
	std::cout << std::endl;
}

//Перераспределяет массив, стирая все данные. Быстрее, чем сохранив их.
void IntegerArray::reallocate(size_t newLength)
{
	//Сначала удаляем имеющиеся элементы
	eraseArray();
	//Проверка на корректность длины
	if (newLength <= 0)
		return;
	//Распределяем ресурсы для новых элементов
	_arrData = new int[newLength];
	_arrLength = newLength;
}

void IntegerArray::resize(size_t newLength)
{
	//Если новая длина равна старой, то ничего не делаем
	if (newLength == _arrLength)
		return;
	//Если новая длина равна нулю, то очищаем элементы
	if (newLength == 0)
	{
		eraseArray();
		return;
	}
	int* newData{ new int[newLength] };

	if (_arrLength > 0)
	{
		size_t elementsToCopy{ (newLength > _arrLength) ? _arrLength : newLength };
		for (size_t index{ 0 }; index < elementsToCopy; ++index)
			newData[index] = _arrData[index];
	}
	delete[] _arrData;
	_arrData = newData;
	_arrLength = newLength;
}

void IntegerArray::insertBefore(int value, size_t index)
{
	lenghtCheck(index); // проверка, что индекс в диапазоне массива

	int* data{ new int[_arrLength + 1] };
	// заполняем новый массив до нужного индекса
	for (size_t before{ 0 }; before < index; ++before)
		data[before] = _arrData[before];

	// заполняем элемент нужного индекса
	data[index] = value;

	// заполняем элементы после нужного индекса
	for (size_t after{ index }; after < _arrLength; ++after)
		data[after+1] = _arrData[after];
	delete[] _arrData;
	_arrData = data;
	++_arrLength;
}

void IntegerArray::remove(size_t index)
{
	lenghtCheck(index);

	if (_arrLength == 1)
	{
		eraseArray();
		return;
	}

	int* data{ new int[_arrLength - 1] };

	// заполняем новый массив до нужного индекса
	for (size_t before{ 0 }; before < index; ++before)
		data[before] = _arrData[before];

	// заполняем элементы после нужного индекса
	for (size_t after{ index+1 }; after < _arrLength; ++after)
		data[after-1] = _arrData[after];
	delete[] _arrData;
	_arrData = data;
	--_arrLength;
}

void IntegerArray::insertAtBegining(int value)
{
	insertBefore(value, 0);
}

void IntegerArray::insertAtEnd(int value)
{
	insertBefore(value, _arrLength);
}

void IntegerArray::find(int value)
{
	size_t count = 0;
	std::cout << "\nИскомое значение " << value << ": ";
	for (int i = 0; i < _arrLength; ++i)
	{
		if (_arrData[i] == value)
		{
			std::cout << i << " ";
			++count;
		}
	}
		if (count == 0)
			std::cout << "не найдено" << std::endl;
}

