#pragma once
#include"Figure.h"
#include <iostream>
using namespace std;


template <class T>
class Square : public  Figure
{
private:
	int storona;
	T** arr;
public:
	Square();
	Square(int s, T val);
	Square(const Square& square);
	~Square();

	int Getstorona();
	T Getval();
	void Setstorona(int _storona);

	float perimetr() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Square& opt);
};


inline Square<char>::Square()
{
	storona = 2;
	arr = new char* [2];
	arr[0] = new char[2];
	arr[0][0] = '#';
}

template<class T>
inline Square<T>::Square(int s, T val)
{
	storona = s;
	arr = new T * [storona];
	for (int i = 0; i < storona; i++)
		arr[i] = new T[storona];

	for (int i = 0; i < storona; i++)
		for (int j = 0; j < storona; j++)
			arr[i][j] = val;
}

template<class T>
inline Square<T>::Square(const Square& square)
{
	if (arr != 0)
	{
		for (int i = 0; i < storona; i++)
			delete[] arr[i];
		delete[] arr;
	}
	storona = square.storona;
	arr = new T * [storona];
	for (int i = 0; i < storona; i++)
		arr[i] = new T[storona];

	for (int i = 0; i < storona; i++)
		for (int j = 0; j < storona; j++)
			arr[i][j] = square.arr[i][j];
}

template<class T>
inline Square<T>::~Square()
{
	if (arr != 0)
	{
		for (int i = 0; i < storona; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		storona = 0;
	}
}

template<class T>
inline int Square<T>::Getstorona()
{
	return storona;
}

template<class T>
inline T Square<T>::Getval()
{
	return arr[0][0];
}

template<class T>
inline void Square<T>::Setstorona(int _storona)
{
	T tmp = arr[0][0];
	if (arr != 0)
	{
		for (int i = 0; i < storona; i++)
			delete[] arr[i];
		delete[] arr;
	}
	storona = _storona;
	arr = new T * [storona];
	for (int i = 0; i < storona; i++)
		arr[i] = new T[storona];

	for (int i = 0; i < storona; i++)
		for (int j = 0; j < storona; j++)
			arr[i][j] = tmp;
}


template<class T>
inline float Square<T>::perimetr()
{
	return 4 * storona;
}

template<class T>
inline ostream& Square<T>::print(ostream& off)
{
	for (int i = 0; i < storona; i++)
	{
		for (int j = 0; j < storona; j++)
			off << arr[i][j];
		off << endl;
	}
	return off;
}

template<class T>
inline bool Square<T>::operator==(const Square& opt)
{
	if (storona == opt.storona && arr[0][0] == opt.arr[0][0])
		return true;
	return false;
}