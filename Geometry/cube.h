#pragma once
#include "figure.h"
#include "square.h"
#include <iostream>
using namespace std;


template <class T>
class Cube : public  Figure
{
private:
	int brink;
	T*** arr;
public:
	Cube();
	Cube(int e, T _val);
	Cube(const Cube& cube);
	~Cube();

	int Getbrink();
	T Getval();
	void Setbrink(int _brink);

	float Perimetr() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Cube& opt);
};

template<class T>
inline Cube<T>::Cube()
{
	brink = 3;
	arr = new T * *[brink];
	for (int i = 0; i < brink; i++)
	{
		arr[i] = new T * [brink];
		for (int j = 0; j < brink; j++)
			arr[i][j] = new T[brink];
	}
	arr[0][0][0] = '&';
}

template<class T>
inline Cube<T>::Cube(int e, T _val)
{
	brink = e;
	arr = new T * *[brink];
	for (int i = 0; i < brink; i++)
	{
		arr[i] = new T * [brink];
		for (int j = 0; j < brink; j++)
			arr[i][j] = new T[brink];
	}
	for (int i = 0; i < brink; i++)
		for (int j = 0; j < brink; j++)
			for (int l = 0; l < brink; l++)
				arr[i][j][l] = _val;
}

template<class T>
inline Cube<T>::Cube(const Cube& cube)
{
	if (arr != 0)
	{
		for (int i = 0; i < brink; i++)
			for (int j = 0; j < brink; j++)
				delete[] arr[i][j];
		for (int i = 0; i < brink; i++)
			delete[] arr[i];
		delete[] arr;
	}
	brink = cube.brink;
	arr = new T * *[brink];
	for (int i = 0; i < brink; i++)
	{
		arr[i] = new T * [brink];
		for (int j = 0; j < brink; j++)
			arr[i][j] = new T[brink];
	}
	for (int i = 0; i < brink; i++)
		for (int j = 0; j < brink; j++)
			for (int l = 0; l < brink; l++)
				arr[i][j][l] = cube.arr[i][j][l];
}

template<class T>
inline Cube<T>::~Cube()
{
	if (arr != 0)
	{
		for (int i = 0; i < brink; i++)
			for (int j = 0; j < brink; j++)
				delete[] arr[i][j];
		for (int i = 0; i < brink; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		brink = 0;
	}
}

template<class T>
inline int Cube<T>::Getbrink()
{
	return brink;
}

template<class T>
inline T Cube<T>::Getval()
{
	return arr[0][0][0];
}

template<class T>
inline void Cube<T>::Setbrink(int _brink)
{
	T tmp = arr[0][0][0];
	if (arr != 0)
	{
		for (int i = 0; i < brink; i++)
			for (int j = 0; j < brink; j++)
				delete[] arr[i][j];
		for (int i = 0; i < brink; i++)
			delete[] arr[i];
		delete[] arr;
	}
	brink = _brink;
	arr = new T * *[brink];
	for (int i = 0; i < brink; i++)
	{
		arr[i] = new T * [brink];
		for (int j = 0; j < brink; j++)
			arr[i][j] = new T[brink];
	}
	for (int i = 0; i < brink; i++)
		for (int j = 0; j < brink; j++)
			for (int l = 0; l < brink; l++)
				arr[i][j][l] = tmp;
}

template<class T>
inline float Cube<T>::Perimetr()
{
	return 12 * brink;
}

template<class T>
inline ostream& Cube<T>::print(ostream& off)
{
	Square<T> tmp(brink, arr[0][0][0]);
	tmp.print(off);
	return off;
}

template<class T>
inline bool Cube<T>::operator==(const Cube& opt)
{
	if (brink == opt.brink && arr[0][0][0] == opt.arr[0][0][0])
		return true;
	return false;
}