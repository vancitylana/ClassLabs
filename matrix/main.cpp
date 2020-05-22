#include <cmath>
#include <iostream>
#include "Matrix.hpp"

int main()
{
    Matrix<int> a,b,c;
    std::cout<<"Ener matrix (n, m, mat): ";
    std::cin>>a;
    b=a;
    std::cout<<"b=a, a==b = "<<static_cast<int>(a==b)<<"\n";
    c = a+b;
    std::cout<<"a + b = \n"<<c<<"\n";
    c = a - b;
    std::cout<<"a - b = \n"<<c<<"\n";
    c = a*b;
    std::cout<<"a * b = \n"<<c<<"\n";
    std::cout<<"a[1][1] = "<<a[1][1]<<"\n";
    
    Vector<int> d,e,f;
    std::cout<<"Ener vector (n, vec): ";
    std::cin>>d;
    e=d;
    std::cout<<"b=a, a==b = "<<static_cast<int>(d==e)<<"\n";
    d.sort_quick(0,d.get_lenght()-1);
    std::cout<<"a.sort() \n"<<d<<"\n";
    f = d+e;
    std::cout<<"a + b = \n"<<f<<"\n";
    f = d - e;
    std::cout<<"a - b = \n"<<f<<"\n";
    f = d*e;
    std::cout<<"a * b = \n"<<f<<"\n";
    f = d/e;
    std::cout<<"a / b = \n"<<f<<"\n";
    std::cout<<"a[1] = "<<d[1]<<"\n";
    std::cout<<"Enter matrix and vec ";
    std::cin>>a>>d;
    auto l = a*d;
    std::cout<<"Mat*vec = "<<l<<"\n";

    return 0;
}
