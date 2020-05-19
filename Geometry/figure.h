#pragma once
#include <iostream>
using namespace std;
class Figure
{
public:
	virtual ~Figure() {}
	virtual float Perimetr() = 0;
	virtual ostream& print(ostream& off) = 0;
	friend ostream& operator<<(ostream& off, Figure& opt)
	{
		return opt.print(off);
	}
	bool operator > (Figure& opt)
	{
		if (this->Perimetr() > opt.Perimetr())
			return true;
		return false;
	}
	bool operator < (Figure& opt)
	{
		if (this->Perimetr() < opt.Perimetr())
			return true;
		return false;
	}
};