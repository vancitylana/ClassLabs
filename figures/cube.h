#pragma once
#include"Figure.h"
#include"Square.h"
#include <iostream>
using namespace std;


template <class T>
class Cube : public  Figure
{
private:
	int rebro;
	T*** arr;
public:
	Cube();
	Cube(int e, T val);
	Cube(const Cube& cube);
	~Cube();

	int Getrebro();
	T Getval();
	void Setrebro(int _rebro);

	float perimetr() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Cube& opt);
};

template<class T>
inline Cube<T>::Cube()
{
	rebro = 3;
	arr = new T * *[rebro];
	for (int i = 0; i < rebro; i++)
	{
		arr[i] = new T * [rebro];
		for (int j = 0; j < rebro; j++)
			arr[i][j] = new T[rebro];
	}
	arr[0][0][0] = '&';
}

template<class T>
inline Cube<T>::Cube(int e, T val)
{
	rebro = e;
	arr = new T * *[rebro];
	for (int i = 0; i < rebro; i++)
	{
		arr[i] = new T * [rebro];
		for (int j = 0; j < rebro; j++)
			arr[i][j] = new T[rebro];
	}
	for (int i = 0; i < rebro; i++)
		for (int j = 0; j < rebro; j++)
			for (int l = 0; l < rebro; l++)
				arr[i][j][l] = val;
}

template<class T>
inline Cube<T>::Cube(const Cube& cube)
{
	if (arr != 0)
	{
		for (int i = 0; i < rebro; i++)
			for (int j = 0; j < rebro; j++)
				delete[] arr[i][j];
		for (int i = 0; i < rebro; i++)
			delete[] arr[i];
		delete[] arr;
	}
	rebro = cube.rebro;
	arr = new T * *[rebro];
	for (int i = 0; i < rebro; i++)
	{
		arr[i] = new T * [rebro];
		for (int j = 0; j < rebro; j++)
			arr[i][j] = new T[rebro];
	}
	for (int i = 0; i < rebro; i++)
		for (int j = 0; j < rebro; j++)
			for (int l = 0; l < rebro; l++)
				arr[i][j][l] = cube.arr[i][j][l];
}

template<class T>
inline Cube<T>::~Cube()
{
	if (arr != 0)
	{
		for (int i = 0; i < rebro; i++)
			for (int j = 0; j < rebro; j++)
				delete[] arr[i][j];
		for (int i = 0; i < rebro; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		rebro = 0;
	}
}

template<class T>
inline int Cube<T>::Getrebro()
{
	return rebro;
}

template<class T>
inline T Cube<T>::Getval()
{
	return arr[0][0][0];
}

template<class T>
inline void Cube<T>::Setrebro(int _rebro)
{
	T tmp = arr[0][0][0];
	if (arr != 0)
	{
		for (int i = 0; i < rebro; i++)
			for (int j = 0; j < rebro; j++)
				delete[] arr[i][j];
		for (int i = 0; i < rebro; i++)
			delete[] arr[i];
		delete[] arr;
	}
	rebro = _rebro;
	arr = new T * *[rebro];
	for (int i = 0; i < rebro; i++)
	{
		arr[i] = new T * [rebro];
		for (int j = 0; j < rebro; j++)
			arr[i][j] = new T[rebro];
	}
	for (int i = 0; i < rebro; i++)
		for (int j = 0; j < rebro; j++)
			for (int l = 0; l < rebro; l++)
				arr[i][j][l] = tmp;
}

template<class T>
inline float Cube<T>::perimetr()
{
	return 12 * rebro;
}

template<class T>
inline ostream& Cube<T>::print(ostream& off)
{
	Square<T> tmp(rebro, arr[0][0][0]);
	tmp.print(off);
	return off;
}

template<class T>
inline bool Cube<T>::operator==(const Cube& opt)
{
	if (rebro == opt.rebro && arr[0][0][0] == opt.arr[0][0][0])
		return true;
	return false;
}