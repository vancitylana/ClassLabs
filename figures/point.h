#pragma once
#include"figure.h"
#include <iostream>
using namespace std;


template <class T>
class Point : public  Figure
{
private:
	T val;
public:
	Point();
	Point(T val);
	Point(const Point& point);

	T Get();

	float Perimetr() override;
	ostream& print(ostream& off) override;

	bool operator ==(const Point& opt);

};

template<class T>
inline Point<T>::Point()
{
	val = '.';
}

template<class T>
inline Point<T>::Point(T val)
{
	val = val;
}

template<class T>
inline Point<T>::Point(const Point& point)
{
	val = point.val;
}

template<class T>
inline T Point<T>::Get()
{
	return val;
}



template<class T>
inline float Point<T>::Perimetr()
{
	return 0;
}

template<class T>
inline ostream& Point<T>::print(ostream& off)
{
	off << this->Get();
	return off;
}

template<class T>
inline bool Point<T>::operator==(const Point& opt)
{
	if (val == opt.val)
		return true;
	return false;
}