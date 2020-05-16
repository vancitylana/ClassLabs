#include <cmath>
#include <iostream>
#include "complex.h"

int main()
{
    Complex a(0.25, 0.25);
    Complex b(a);
    Complex c = a + b;
    c.print_trig(std::cout);
    std::cout << "\n";

    return 0;
}
