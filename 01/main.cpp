// Домашнее задание к занятию «Шаблоны и функторы»
// Задача 1. Возведение в квадрат

#include <iostream>
#include <vector>
#include <string>

//Шаблон для Возведение в квадрат числа
template <class T>
T degree(T num)
{
	return num * num;
};

//Специализация шаблона для string
template <>
std::string degree(std::string num)
{
	return num;
};

//Шаблон для Возведение в квадрат вектора
template <class T>
std::vector<T> degree(std::vector<T> b)
{
	for (size_t i = 0; i < b.size(); i++)
	{
		b.at(i) *= b.at(i);
	};
	return b;
};

//Печать вектора
void printVector(std::vector<int>* v1)
{
	for (size_t i = 0; i < v1->size(); i++)
	{
		std::cout << v1->at(i) << "\t";
	};
};

int main()
{
	setlocale(LC_ALL, "ru");
	
	int a = 5;
	int x = degree(a);

	std::cout << "degree <int>(a) = " << x << std::endl;
	std::cout << "degree <string>(Privet) = " << degree <std::string>("Privet") << std::endl;
	std::cout << "degree <int>(2) = " << degree <int>(2) << std::endl;
	std::cout << "degree <double>(3.5) = " << degree <double>(3.5) << std::endl;
	std::cout << std::endl;

	std::vector<int> b = { -1, 4, 8, -7, 0 };

	std::cout << "Вектор b до" << std::endl;
	printVector(&b);
	std::cout << std::endl;

	std::vector<int> y = degree(b);

	std::cout << "Вектор y" << std::endl;
	printVector(&y);
	
	std::cout << std::endl << "Вектор b после" << std::endl;
	printVector(&b);
	
	std::cout << std::endl;
	std::cout << std::endl;
};