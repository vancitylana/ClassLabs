#pragma once
#include "figure.h"
#include "point.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "cube.h"
#include "simplex.h"


class Container
{
private:
	Figure** arr;
	int size;
public:
	Container();
	~Container();

	template <class A>
	void Add(A& elem);
	template <class A>
	void Delete(A& elem);
	template <class A>
	void Off(A& elem);

	Figure* operator[](const int i);
	friend ostream& operator<<(ostream& off, Container& opt);
};


Container::Container()
{
	size = 0;
	arr = 0;
}


Container::~Container()
{
	delete[] arr;
}

Figure* Container::operator[](const int i)
{
	return arr[i];
}


template<class A>
void Container::Add(A& elem)
{
	Figure** tmp = new Figure * [size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	delete[]arr;
	size++;
	arr = new Figure * [size];
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = tmp[i];
	}
	arr[size - 1] = &elem;
	delete[]tmp;
}

template<class A>
void Container::Delete(A& elem)
{
	Figure** tmp = new Figure * [size];
	int j = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == &elem)
		{
			k = 1;
		}
		else
		{
			tmp[j] = arr[i];
			j++;
		}
	}
	if (k == 0)
		throw - 1;
	delete[] arr;
	arr = new Figure * [size - 1];
	size = size - 1;
	for (int i = 0; i < size; i++)
		arr[i] = tmp[i];
	delete tmp;
}

template<class A>
void Container::Off(A& elem)
{
	cout << elem;
}

ostream& operator<<(ostream& off, Container& opt)
{
	for (int i = 0; i < opt.size; i++)
	{
		off << *(opt[i]) << endl;
	}
	return off;
}