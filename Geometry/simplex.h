#pragma once
#include "figure.h"
#include <iostream>
using namespace std;


template <class T>
class Simplex : public  Figure
{
private:
	int Vusota;
	T** arr;

public:
	Simplex();
	Simplex(int _Vusota, T _val);
	Simplex(const Simplex& simplex);
	~Simplex();

	int GetVusota();
	T Getval();
	void SetVusota(int _Vusota);

	float Perimetr() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Simplex& opt);
};


inline Simplex<char>::Simplex()
{
	Vusota = 5;
	arr = new char* [Vusota];
	for (int i = 0; i < Vusota; i++)
		arr[i] = new char[Vusota];
	for (int i = 0; i < Vusota; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = '^';
}

template<class T>
inline Simplex<T>::Simplex(int _Vusota, T _val)
{
	Vusota = _Vusota + 1;

	arr = new T * [Vusota];
	for (int i = 0; i < Vusota; i++)
		arr[i] = new T[Vusota];


	for (int i = 0; i < Vusota; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = _val;
}

template<class T>
inline Simplex<T>::Simplex(const Simplex& simplex)
{
	if (arr != 0)
	{
		for (int i = 0; i < Vusota; i++)
			delete[] arr[i];
		delete[] arr;
	}
	Vusota = simplex.Vusota;

	arr = new T * [Vusota];
	for (int i = 0; i < Vusota; i++)
		arr[i] = new T[Vusota];


	for (int i = 0; i < Vusota; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = simplex.arr[i][j];
}

template<class T>
inline Simplex<T>::~Simplex()
{
	if (arr != 0)
	{
		for (int i = 0; i < Vusota; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		Vusota = 0;
	}
}

template<class T>
inline int Simplex<T>::GetVusota()
{
	return Vusota - 1;
}

template<class T>
inline T Simplex<T>::Getval()
{
	return T();
}

template<class T>
inline void Simplex<T>::SetVusota(int _Vusota)
{
	T tmp = this->Getval();
	if (arr != 0)
	{
		for (int i = 0; i < Vusota; i++)
			delete[] arr[i];
		delete[] arr;
	}
	Vusota = _Vusota + 1;


	arr = new T * [Vusota];
	for (int i = 0; i < Vusota; i++)
		arr[i] = new T[Vusota];

	for (int i = 0; i < Vusota; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = tmp;
}

template<class T>
inline float Simplex<T>::Perimetr()
{
	return 3 * (Vusota - 1);
}

template<class T>
inline ostream& Simplex<T>::print(ostream& off)
{
	for (int i = 0; i < Vusota; i++)
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
	if (Vusota == opt.Vusota && arr[0][0] == opt.arr[0][0])
		return true;
	return false;
}