#pragma once
#include "figure.h"
#include <iostream>
using namespace std;


template <class T>
class Line : public  Figure
{
private:
	int dlina;
	T* arr;
public:
	Line();
	Line(int Dlina, T _val);
	Line(const Line& line);
	~Line();

	int GetDlina();
	T Getval();
	void SetDlina(int Dlina);


	float Perimetr() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Line& opt);
};

template<class T>
inline Line<T>::Line()
{
	dlina = 8;
	arr = new char[dlina];
	for (int i = 0; i < dlina; i++)
		arr[i] = "-";
}

template<class T>
inline Line<T>::Line(int Dlina, T _val)
{
	dlina = Dlina;
	arr = new T[dlina];
	for (int i = 0; i < dlina; i++)
		arr[i] = _val;
}

template<class T>
inline Line<T>::Line(const Line& line)
{
	if (arr != 0)
		delete[] arr;
	dlina = line.dlina;
	arr = new T[dlina];
	for (int i = 0; i < dlina; i++)
		arr[i] = line.arr[i];
}

template<class T>
inline Line<T>::~Line()
{
	if (arr != 0)
	{
		delete[] arr;
		arr = 0;
		dlina = 0;
	}
}

template<class T>
inline int Line<T>::GetDlina()
{
	return dlina;
}

template<class T>
inline T Line<T>::Getval()
{
	return arr[0];
}

template<class T>
inline void Line<T>::SetDlina(int Dlina)
{
	T tmp = arr[0];
	if (arr != 0)
		delete[] arr;
	dlina = Dlina;
	arr = new T[dlina];
	for (int i = 0; i < dlina; i++)
		arr[i] = tmp;
}


template<class T>
inline float Line<T>::Perimetr()
{
	return 0;
}

template<class T>
inline ostream& Line<T>::print(ostream& off)
{
	for (int i = 0; i < dlina; i++)
		off << arr[i];
	off << endl;
	return off;
}

template<class T>
inline bool Line<T>::operator==(const Line& opt)
{
	if (dlina == opt.dlina && arr[0] == opt.arr[0])
		return true;
	return false;
}