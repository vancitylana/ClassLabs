#include "forms.h"

void gosudarstvo::play() 
{
	cout << "hehe\n" << endl;
}

void gosudarstvo::getexample() 
{
	cout << example << endl;
}

void gosudarstvo::getsum() 
{
	if (sum < 0)
		cout << "o my god\n";
	else
		cout << sum << endl;
}
ystroistvo::ystroistvo()
{
	example = "example";
	sum = 250;
}
void ystroistvo::play()
{
	cout << "oops\n" << endl;
}
pravlenie::pravlenie()
{
	example = "ExAmPlE";
	sum = 230;
}
void pravlenie::play()
{
	cout << "mda\n" << endl;
}
polit_rejim::polit_rejim()
{
	example = "eXaMpLe";
	sum = 200;
}
monarchy::monarchy()
{
	example = "England";
	sum = 30;
}
void monarchy::play()
{
	cout << "God save the Queen\n" << endl;
}
republic::republic()
{
	example = "Russia";
	sum = 27;
}
void republic::play()
{
	cout << "No Queen\n" << endl;
}
totalitarism::totalitarism()
{
	example = "North Korea";
	sum = 13;
}
avtoritarism::avtoritarism()
{
	example = "Iran";
	sum = 15;
}
democratic::democratic()
{
	example = "USA";
	sum = 167;
}
federation::federation()
{
	example = "India";
}
void federation::play()
{
	cout << "Many subject\n" << endl;
}
unitarnoe::unitarnoe()
{
	example = "Greece";
}
void unitarnoe::play()
{
	cout << "No subject\n" << endl;
}
confederation::confederation()
{
	example = "European Union";
}
void confederation::play()
{
	cout << "Bye UK!!!\n" << endl;
}
void confederation::play(int n) 
{
	switch (n)
	{
	case 1:
		cout << "Britain\n";
		break;
	case 2:
		cout << "Exit\n";
		break;
	default:
		cout << "B r E x I t\n";
		break;
	}
}
