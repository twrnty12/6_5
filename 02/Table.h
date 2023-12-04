#pragma once
#include <iostream>
#include <array>
#include <exception>

template<class T>
class Table
{
private:
	T** arr1_;
	int arrSizeRow_ = 0;
	int arrSizeCol_ = 0;
	int size_ = 0;

public:
	//����������� ������� ��������� ������
	Table(int arrSizeRow, int arrSizeCol) : arrSizeRow_{arrSizeRow}, arrSizeCol_(arrSizeCol)
	{
		arr1_ = new T* [arrSizeRow_] {};
		for (int i = 0; i < arrSizeRow_; i++)
		{
			arr1_[i] = new T[arrSizeCol_] {};
		}
		std::cout << "����������� " << this << std::endl;
	};

	//����������� �����������
	Table(const Table& other)
	{
		//����������� ������� �� ������1(other)
		this->arrSizeRow_ = other.arrSizeRow_;
		this->arrSizeCol_ = other.arrSizeCol_;

		//������� ����� ������2 ������� ��� ������1(other) � �������� ��������.
		arr1_ = new T * [this->arrSizeRow_] {};
		for (int i = 0; i < this->arrSizeRow_; i++)
		{
			arr1_[i] = new T[this->arrSizeCol_]{};
		}
		std::cout << "����������� " << this << std::endl;

		//�������� �������� �� ������1(other) � ������2
		for (size_t i = 0; i < other.arrSizeRow_; i++)
		{
			for (size_t j = 0; j < other.arrSizeCol_; j++)
			{
				this->arr1_[i][j] = other.arr1_[i][j];
			}
		}
		std::cout << std::endl;

		std::cout << this << " - ����������� ����������� Table(const Table& other)\n\n";
	};

	//�������� ()
	T& operator()(int i,int j)
	{
		if (i >= arrSizeRow_ || i < 0) throw std::out_of_range("out_of_range index i(one)");
		if(j >= arrSizeCol_ || j < 0) throw std::out_of_range("out_of_range index j(one)");

		return arr1_[i][j];
	};

	//���������� operator[] ��� ���������� �������
	class ArrayRow
	{
	public:
		ArrayRow(T* arrayRow_, const int arrSizeCol) : arrayRow_(arrayRow_), arrSizeCol_(arrSizeCol) { }

		T& operator[](int i)
		{
			if (i >= arrSizeCol_ || i < 0) throw std::out_of_range("out_of_range index j(two)");
			return arrayRow_[i];
		}
	private:
		T* arrayRow_;
		int arrSizeCol_ = 0;
	};
	ArrayRow operator[](const int i) const
	{
		if (i >= arrSizeRow_ || i < 0) throw std::out_of_range("out_of_range index i(one)");

		return ArrayRow(arr1_[i], arrSizeCol_);
	};

	//�������� ������� ����������� ������ ������� � ������
	//Table& operator=(const Table& other) = delete;

	//�������� ������������
	Table& operator=(const Table& other)
	{
		if (this != &other)
		{
			//����������� ������� �� ������1(other)
			this->arrSizeCol_ = other.arrSizeCol_;
			this->arrSizeRow_ = other.arrSizeRow_;

			//��������(��������) ���������� ������� this, ���� ����� ����
			this->~Table();

			//������� ����� ������
			arr1_ = new T * [arrSizeRow_] {};
			for (int i = 0; i < arrSizeRow_; i++)
			{
				arr1_[i] = new T[arrSizeCol_]{};
			}
			std::cout << "����������� " << this << std::endl;

			//�������� �������� �� ������� ������� � �����
			for (size_t i = 0; i < other.arrSizeRow_; i++)
			{
				for (size_t j = 0; j < other.arrSizeCol_; j++)
				{
					this->arr1_[i][j] = other.arr1_[i][j];
				}
			}

			std::cout << this << " - �������� ����������� Table& operator=(const Table& other)\n\n";

			return *this;
		};
		std::cout << "�� ��������� ����������� ������ ��� � ����\n";
		return *this;
	};

	//����� ������� ������ �������
	void getSize()
	{
		std::cout << "Size Of Array: " << arrSizeRow_ << " x " << arrSizeCol_ << std::endl << std::endl;
	};

	//����� ������ �������
	void printArr() 
	{
		for (size_t i = 0; i < arrSizeRow_; i++)
		{
			for (size_t j = 0; j < arrSizeCol_; j++)
			{
				std::cout << arr1_[i][j] << '\t';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	};

	~Table()
	{
		for (size_t j = 0; j < this->arrSizeRow_; j++)
		{
			delete[] this->arr1_[j];
		}
		delete[] this->arr1_;
		this->arr1_ = nullptr;
		std::cout << "���������� " << this << std::endl;
	}
};