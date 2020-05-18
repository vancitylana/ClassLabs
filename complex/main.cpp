#include <cmath>
#include <iostream>
#include "complex.h"

int main()
{
    Complex a;
    Complex b(2,1);
    Complex c(b);
    std::cout<<"A= "<<a<<" B= "<<b<<" C= "<<c<<'\n';
    Complex d = b+c;
    std::cout<<"B + C = ";
    std::cout<<d<<'\n';
    d = b-c;
    std::cout<<"B - C = ";
    std::cout<<d<<'\n';
    d = b*c;
    std::cout<<"B * C = ";
    std::cout<<d<<'\n';
    d = b/c;
    std::cout<<"B / C = ";
    std::cout<<d<<'\n';
    std::cout<<"B == C = ";
    std::cout<<static_cast<int>(b==c)<<'\n';
    d=a;
    std::cout<<"D = ";
    std::cout<<d<<'\n';
    std::cout<<"|B| = ";
    std::cout<<b.module()<<'\n';
    std::cout<<"Trig. B: ";
    b.print_trig(std::cout);
    std::cout<<'\n';
    b.pow(b);
    std::cout<<"B ^ B = ";
    std::cout<<b<<'\n';


    return 0;
}
