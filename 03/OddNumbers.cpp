#include "OddNumbers.h"

void OddNumbers::operator ()(int value)
{
	if (value % 3 == 0)
	{
		sum_ += value;
		count_++;
	};
};

int OddNumbers::getSum()
{
	count_++;
	std::cout << "Функтор: Cумма нечетных чисел = " << sum_ << std::endl;
	return sum_;
};

int OddNumbers::getCount()
{
	std::cout << "Функтор: Количество вызовов функции = " << count_ << std::endl;
	return count_;
};
