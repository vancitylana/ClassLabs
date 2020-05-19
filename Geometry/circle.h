#pragma once
#include "figure.h"
#include <iostream>
using namespace std;


template <class T>
class Circle : public Figure
{
private:
	int Diametr;
	T** arr;
public:
	Circle();
	Circle(int diam, T _val);
	Circle(const Circle& circle);
	~Circle();

	int GetDiametr();
	T Getval();
	void SetDiametr(int _Diametr);

	float Perimetr() override;
	ostream& print(ostream& off) override;


	bool operator ==(const Circle& opt);
};

inline Circle<char>::Circle()
{
	Diametr = 2;
	arr = new char* [2 * Diametr - 1];
	for (int i = 0; i < 2 * Diametr - 1; i++)
		arr[i] = new char[2 * Diametr];

	for (int i = 0; i < Diametr; i++)
		for (int j = Diametr - 1 - i; j < Diametr + i + 1; j++)
			arr[i][j] = '@';

	for (int i = Diametr; i < 2 * Diametr - 1; i++)
		for (int j = 1 + i - Diametr; j < 3 * Diametr - 1 - i; j++)
			arr[i][j] = '@';

}

template<class T>
inline Circle<T>::Circle(int diam, T _val)
{
	Diametr = diam;
	arr = new T * [2 * Diametr - 1];
	for (int i = 0; i < 2 * Diametr - 1; i++)
		arr[i] = new T[2 * Diametr];

	for (int i = 0; i < Diametr; i++)
		for (int j = Diametr - 1 - i; j < Diametr + i + 1; j++)
			arr[i][j] = _val;

	for (int i = Diametr; i < 2 * Diametr - 1; i++)
		for (int j = 1 + i - Diametr; j < 3 * Diametr - 1 - i; j++)
			arr[i][j] = _val;
}

template<class T>
inline Circle<T>::Circle(const Circle& circle)
{
	if (arr != 0)
	{
		for (int i = 0; i < 2 * Diametr - 1; i++)
			delete[] arr[i];
		delete[] arr;
	}
	Diametr = circle.Diametr;
	arr = new T * [2 * Diametr - 1];
	for (int i = 0; i < 2 * Diametr - 1; i++)
		arr[i] = new T[2 * Diametr];

	for (int i = 0; i < Diametr; i++)
		for (int j = Diametr - 1 - i; j < Diametr + i + 1; j++)
			arr[i][j] = circle.arr[i][j];

	for (int i = Diametr; i < 2 * Diametr - 1; i++)
		for (int j = 1 + i - Diametr; j < 3 * Diametr - 1 - i; j++)
			arr[i][j] = circle.arr[i][j];
}

template<class T>
inline Circle<T>::~Circle()
{
	if (arr != 0)
	{
		for (int i = 0; i < 2 * Diametr - 1; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		Diametr = 0;
	}
}

template<class T>
inline int Circle<T>::GetDiametr()
{
	return Diametr;
}

template<class T>
inline T Circle<T>::Getval()
{
	return arr[Diametr][Diametr];
}

template<class T>
inline void Circle<T>::SetDiametr(int _Diametr)
{
	T tmp = this->Getval();
	if (arr != 0)
	{
		for (int i = 0; i < 2 * Diametr - 1; i++)
			delete[] arr[i];
		delete[] arr;
	}
	Diametr = _Diametr;
	arr = new T * [2 * Diametr - 1];
	for (int i = 0; i < 2 * Diametr - 1; i++)
		arr[i] = new T[2 * Diametr];

	for (int i = 0; i < Diametr; i++)
		for (int j = Diametr - 1 - i; j < Diametr + i + 1; j++)
			arr[i][j] = tmp;

	for (int i = Diametr; i < 2 * Diametr - 1; i++)
		for (int j = 1 + i - Diametr; j < 3 * Diametr - 1 - i; j++)
			arr[i][j] = tmp;
}

template<class T>
inline float Circle<T>::Perimetr()
{
	return Diametr * 3.14;
}

template<class T>
inline ostream& Circle<T>::print(ostream& off)
{
	for (int i = 0; i < 2 * Diametr - 1; i++)
	{
		for (int j = 0; j < 2 * Diametr; j++)
		{
			if ((i < Diametr && j >= (Diametr - 1 - i) && j < (Diametr + i + 1)) || (i >= Diametr && i < (2 * Diametr - 1) && j >= (1 + i - Diametr) && j < (3 * Diametr - 1 - i)))
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
	if (Diametr == opt.Diametr && arr[Diametr][Diametr] == opt.arr[Diametr][Diametr])
		return true;
	return false;
}