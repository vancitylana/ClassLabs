#include <iostream>
#include "figure.h"
#include "point.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "cube.h"
#include "simplex.h"
#include "container.h"
using namespace std;


int main()
{
	Container Cont;
	Point<char> point;
	Line<char> line(10, '_');
	Circle<char> circle(3, '^');
	Square<int> square(6, 0);
	Rectangle<int> rectangle(2, 6, 5);
	Cube<char> cube(4, '+');
	Simplex<char> simplex(4, '=');


	Cont.Add(point);
	Cont.Add(line);
	Cont.Add(square);
	Cont.Add(rectangle);
	Cont.Add(circle);
	Cont.Add(cube);
	Cont.Add(simplex);


	cout << "point:" << endl;
	Cont.Off(point);
	cout << endl;
	cout << "line:" << endl;
	Cont.Off(line);
	cout << endl;
	cout << "circle:" << endl;
	Cont.Off(circle);
	cout << endl;
	cout << "square:" << endl;
	Cont.Off(square);
	cout << endl;
	cout << "rectangle:" << endl;
	Cont.Off(rectangle);
	cout << endl;
	cout << "simplex projection:" << endl;
	Cont.Off(simplex);
	cout << endl;
	cout << "cube projection:" << endl;
	Cont.Off(cube);

	if (square.Perimetr() > cube.Perimetr())
		Cont.Delete(cube);
	if (square.Perimetr() < cube.Perimetr())
		Cont.Delete(square);

	cout << "Container" << endl << Cont;
	return 0;
}