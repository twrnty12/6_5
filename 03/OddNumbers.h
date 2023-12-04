#pragma once
#include <iostream>

class OddNumbers
{
private:
	int count_ = 0;
	int sum_ = 0;

public:
	OddNumbers() = default;

	void operator ()(int value);
	int getSum();
	int getCount();
};

