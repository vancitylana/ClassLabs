#pragma once
#include"Figure.h"
#include <iostream>
using namespace std;


template <class T>
class Circle : public Figure
{
private:
	int diametr;
	T** arr;
public:
	Circle();
	Circle(int diam, T val);
	Circle(const Circle& circle);
	~Circle();

	int Getdiametr();
	T Getval();
	void Setdiametr(int _diametr);

	float perimetr() override;
	ostream& print(ostream& off) override;


	bool operator ==(const Circle& opt);
};

inline Circle<char>::Circle()
{
	diametr = 2;
	arr = new char* [2 * diametr - 1];
	for (int i = 0; i < 2 * diametr - 1; i++)
		arr[i] = new char[2 * diametr];

	for (int i = 0; i < diametr; i++)
		for (int j = diametr - 1 - i; j < diametr + i + 1; j++)
			arr[i][j] = '@';

	for (int i = diametr; i < 2 * diametr - 1; i++)
		for (int j = 1 + i - diametr; j < 3 * diametr - 1 - i; j++)
			arr[i][j] = '@';

}

template<class T>
inline Circle<T>::Circle(int diam, T val)
{
	diametr = diam;
	arr = new T * [2 * diametr - 1];
	for (int i = 0; i < 2 * diametr - 1; i++)
		arr[i] = new T[2 * diametr];

	for (int i = 0; i < diametr; i++)
		for (int j = diametr - 1 - i; j < diametr + i + 1; j++)
			arr[i][j] = val;

	for (int i = diametr; i < 2 * diametr - 1; i++)
		for (int j = 1 + i - diametr; j < 3 * diametr - 1 - i; j++)
			arr[i][j] = val;
}

template<class T>
inline Circle<T>::Circle(const Circle& circle)
{
	if (arr != 0)
	{
		for (int i = 0; i < 2 * diametr - 1; i++)
			delete[] arr[i];
		delete[] arr;
	}
	diametr = circle.diametr;
	arr = new T * [2 * diametr - 1];
	for (int i = 0; i < 2 * diametr - 1; i++)
		arr[i] = new T[2 * diametr];

	for (int i = 0; i < diametr; i++)
		for (int j = diametr - 1 - i; j < diametr + i + 1; j++)
			arr[i][j] = circle.arr[i][j];

	for (int i = diametr; i < 2 * diametr - 1; i++)
		for (int j = 1 + i - diametr; j < 3 * diametr - 1 - i; j++)
			arr[i][j] = circle.arr[i][j];
}

template<class T>
inline Circle<T>::~Circle()
{
	if (arr != 0)
	{
		for (int i = 0; i < 2 * diametr - 1; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		diametr = 0;
	}
}

template<class T>
inline int Circle<T>::Getdiametr()
{
	return diametr;
}

template<class T>
inline T Circle<T>::Getval()
{
	return arr[diametr][diametr];
}

template<class T>
inline void Circle<T>::Setdiametr(int _diametr)
{
	T tmp = this->Getval();
	if (arr != 0)
	{
		for (int i = 0; i < 2 * diametr - 1; i++)
			delete[] arr[i];
		delete[] arr;
	}
	diametr = _diametr;
	arr = new T * [2 * diametr - 1];
	for (int i = 0; i < 2 * diametr - 1; i++)
		arr[i] = new T[2 * diametr];

	for (int i = 0; i < diametr; i++)
		for (int j = diametr - 1 - i; j < diametr + i + 1; j++)
			arr[i][j] = tmp;

	for (int i = diametr; i < 2 * diametr - 1; i++)
		for (int j = 1 + i - diametr; j < 3 * diametr - 1 - i; j++)
			arr[i][j] = tmp;
}

template<class T>
inline float Circle<T>::perimetr()
{
	return diametr * 3.14;
}

template<class T>
inline ostream& Circle<T>::print(ostream& off)
{
	for (int i = 0; i < 2 * diametr - 1; i++)
	{
		for (int j = 0; j < 2 * diametr; j++)
		{
			if ((i < diametr && j >= (diametr - 1 - i) && j < (diametr + i + 1)) || (i >= diametr && i < (2 * diametr - 1) && j >= (1 + i - diametr) && j < (3 * diametr - 1 - i)))
				off << arr[i][j];
			else off << " ";
		}
		off << endl;
	}
	return off;
}

template<class T>
inline bool Circle<T>::operator==(const Circle& opt)
{
	if (diametr == opt.diametr && arr[diametr][diametr] == opt.arr[diametr][diametr])
		return true;
	return false;
}