#pragma once
#include"Figure.h"
#include <iostream>
using namespace std;


template <class T>
class Line : public  Figure
{
private:
	int length;
	T* arr;
public:
	Line();
	Line(int leng, T val);
	Line(const Line& line);
	~Line();

	int GetLeng();
	T Getval();
	void SetLeng(int leng);


	float perimetr() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Line& opt);
};

template<class T>
inline Line<T>::Line()
{
	length = 8;
	arr = new char[length];
	for (int i = 0; i < length; i++)
		arr[i] = "-";
}

template<class T>
inline Line<T>::Line(int leng, T val)
{
	length = leng;
	arr = new T[length];
	for (int i = 0; i < length; i++)
		arr[i] = val;
}

template<class T>
inline Line<T>::Line(const Line& line)
{
	if (arr != 0)
		delete[] arr;
	length = line.length;
	arr = new T[length];
	for (int i = 0; i < length; i++)
		arr[i] = line.arr[i];
}

template<class T>
inline Line<T>::~Line()
{
	if (arr != 0)
	{
		delete[] arr;
		arr = 0;
		length = 0;
	}
}

template<class T>
inline int Line<T>::GetLeng()
{
	return length;
}

template<class T>
inline T Line<T>::Getval()
{
	return arr[0];
}

template<class T>
inline void Line<T>::SetLeng(int leng)
{
	T tmp = arr[0];
	if (arr != 0)
		delete[] arr;
	length = leng;
	arr = new T[length];
	for (int i = 0; i < length; i++)
		arr[i] = tmp;
}


template<class T>
inline float Line<T>::perimetr()
{
	return 0;
}

template<class T>
inline ostream& Line<T>::print(ostream& off)
{
	for (int i = 0; i < length; i++)
		off << arr[i];
	off << endl;
	return off;
}

template<class T>
inline bool Line<T>::operator==(const Line& opt)
{
	if (length == opt.length && arr[0] == opt.arr[0])
		return true;
	return false;
}