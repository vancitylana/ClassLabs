#pragma once
#include "figure.h"
#include <iostream>
using namespace std;


template <class T>
class Rectangle : public  Figure
{
private:
	int storona1;
	int storona2;
	T** arr;
public:
	Rectangle();
	Rectangle(int _storona1, int _storona2, T _val);
	Rectangle(const Rectangle& rectangle);
	~Rectangle();

	int Getstorona1();
	int Getstorona2();
	T Getval();
	void Setstorona(int _storona1, int _storona2);

	float Perimetr() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Rectangle& opt);
};


inline Rectangle<char>::Rectangle()
{
	storona1 = 1;
	storona2 = 1;
	arr = new char* [1];
	arr[0] = new char[1];
	arr[0][0] = '+';
}

template<class T>
inline Rectangle<T>::Rectangle(int _storona1, int _storona2, T _val)
{
	storona1 = _storona1;
	storona2 = _storona2;
	arr = new T * [storona1];
	for (int i = 0; i < storona1; i++)
		arr[i] = new T[storona2];

	for (int i = 0; i < storona1; i++)
		for (int j = 0; j < storona2; j++)
			arr[i][j] = _val;
}

template<class T>
inline Rectangle<T>::Rectangle(const Rectangle& rectangle)
{
	if (arr != 0)
	{
		for (int i = 0; i < storona1; i++)
			delete[] arr[i];
		delete[] arr;
	}
	storona1 = rectangle.storona1;
	storona2 = rectangle.storona2;
	arr = new T * [storona1];
	for (int i = 0; i < storona1; i++)
		arr[i] = new T[storona2];

	for (int i = 0; i < storona1; i++)
		for (int j = 0; j < storona2; j++)
			arr[i][j] = rectangle.arr[i][j];
}

template<class T>
inline Rectangle<T>::~Rectangle()
{
	if (arr != 0)
	{
		for (int i = 0; i < storona1; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		storona1 = 0;
		storona2 = 0;
	}
}

template<class T>
inline int Rectangle<T>::Getstorona1()
{
	return storona1;
}

template<class T>
inline int Rectangle<T>::Getstorona2()
{
	return storona2;
}

template<class T>
inline T Rectangle<T>::Getval()
{
	return arr[0][0];
}

template<class T>
inline void Rectangle<T>::Setstorona(int _storona1, int _storona2)
{
	T tmp = arr[0][0];
	if (arr != 0)
	{
		for (int i = 0; i < storona1; i++)
			delete[] arr[i];
		delete[] arr;
	}
	storona1 = _storona1;
	storona2 = _storona2;
	arr = new T * [storona1];
	for (int i = 0; i < storona1; i++)
		arr[i] = new T[storona2];

	for (int i = 0; i < storona1; i++)
		for (int j = 0; j < storona2; j++)
			arr[i][j] = tmp;
}


template<class T>
inline float Rectangle<T>::Perimetr()
{
	return 2 * (storona1 + storona2);
}

template<class T>
inline ostream& Rectangle<T>::print(ostream& off)
{
	for (int i = 0; i < storona1; i++)
	{
		for (int j = 0; j < storona2; j++)
			off << arr[i][j];
		off << endl;
	}
	return off;
}

template<class T>
inline bool Rectangle<T>::operator==(const Rectangle& opt)
{
	if (storona1 == opt.storona1 && storona2 == opt.storona2 && arr[0][0] == opt.arr[0][0])
		return true;
	return false;
}