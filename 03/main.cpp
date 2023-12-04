// 03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "OddNumbers.h"
#include <vector>

int main()
{
    setlocale(LC_ALL, "ru");
    
    OddNumbers oddNum;
    std::vector<int> vec;

    for (size_t i = 0; i < 11; i++)
    {
        vec.push_back(i*2);
    }
       
    for (auto value : vec)
    {
        std::cout << value << "\t";
    };

    std::cout << "\n\n";

    for (auto value : vec)
    {
        oddNum(value);
    };

    oddNum.getCount();
    oddNum.getSum();

    
    std::cout << "\n\nHello World!\n\n";
}