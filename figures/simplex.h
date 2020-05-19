#pragma once
#include"Figure.h"
#include <iostream>
using namespace std;


template <class T>
class Simplex : public  Figure
{
private:
	int height;
	T** arr;

public:
	Simplex();
	Simplex(int _height, T val);
	Simplex(const Simplex& simplex);
	~Simplex();

	int GetHeight();
	T Getval();
	void SetHeight(int _height);

	float perimetr() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Simplex& opt);
};


inline Simplex<char>::Simplex()
{
	height = 5;
	arr = new char* [height];
	for (int i = 0; i < height; i++)
		arr[i] = new char[height];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = '^';
}

template<class T>
inline Simplex<T>::Simplex(int _height, T val)
{
	height = _height + 1;

	arr = new T * [height];
	for (int i = 0; i < height; i++)
		arr[i] = new T[height];


	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = val;
}

template<class T>
inline Simplex<T>::Simplex(const Simplex& simplex)
{
	if (arr != 0)
	{
		for (int i = 0; i < height; i++)
			delete[] arr[i];
		delete[] arr;
	}
	height = simplex.height;

	arr = new T * [height];
	for (int i = 0; i < height; i++)
		arr[i] = new T[height];


	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = simplex.arr[i][j];
}

template<class T>
inline Simplex<T>::~Simplex()
{
	if (arr != 0)
	{
		for (int i = 0; i < height; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		height = 0;
	}
}

template<class T>
inline int Simplex<T>::GetHeight()
{
	return height - 1;
}

template<class T>
inline T Simplex<T>::Getval()
{
	return T();
}

template<class T>
inline void Simplex<T>::SetHeight(int _height)
{
	T tmp = this->Getval();
	if (arr != 0)
	{
		for (int i = 0; i < height; i++)
			delete[] arr[i];
		delete[] arr;
	}
	height = _height + 1;


	arr = new T * [height];
	for (int i = 0; i < height; i++)
		arr[i] = new T[height];

	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = tmp;
}

template<class T>
inline float Simplex<T>::perimetr()
{
	return 3 * (height - 1);
}

template<class T>
inline ostream& Simplex<T>::print(ostream& off)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < i; j++)
			off << arr[i][j];
		off << endl;
	}
	return off;
}

template<class T>
inline bool Simplex<T>::operator==(const Simplex& opt)
{
	if (height == opt.height && arr[0][0] == opt.arr[0][0])
		return true;
	return false;
}