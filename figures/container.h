#pragma once
#include"Figure.h"
#include"Point.h"
#include"Line.h"
#include"Circle.h"
#include"Square.h"
#include"Rectangle.h"
#include"Cube.h"
#include"Simplex.h"


class Container
{
private:
	Figure** arr;
	int size;
public:
	Container();
	~Container();

	template <class A>
	void Add(A& element);
	template <class A>
	void Delete(A& element);
	template <class A>
	void Off(A& element);

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
void Container::Add(A& element)
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
	arr[size - 1] = &element;
	delete[]tmp;
}

template<class A>
void Container::Delete(A& element)
{
	Figure** tmp = new Figure * [size];
	int j = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == &element)
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
void Container::Off(A& element)
{
	cout << element;
}

ostream& operator<<(ostream& off, Container& opt)
{
	for (int i = 0; i < opt.size; i++)
	{
		off << *(opt[i]) << endl;
	}
	return off;
}