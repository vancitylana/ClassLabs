#include <cmath>
#include <iostream>
#include "String.h"

int main()
{
    String a("ffabcabcabc");
    String b("abc");
    String c = b;
    String d = a + b;
    std::cout << "a = " << a << "; b = " << b << "; c = b = " << c << "; d = a + b = " << d << ";\n";
    std::cout << "a == b = " << static_cast<int>(a == b) << "\n";
    std::cout << "a > b = " << static_cast<int>(a > b) << "\n";
    std::cout << "a < b = " << static_cast<int>(a < b) << "\n";
    std::cout << "a[2] = " << a[2] << "\n";
    std::cout << "a.substr_first(b) = " << a.substr_first(b) << "\n";
    std::cout << "a.subsymb('a') = " << a.subsymb('a') << "\n";
    std::cout << "a.split('a') : " << "\n";
    String* res = a.split('a');
    int idx = 0;
    while (res[idx].get_size() != -1)
    {
        std::cout << res[idx] << ' ';
        ++idx;
    }
    std::cout << "\n";
    b.dub_k(10);
    std::cout << "b.dub_k(10): " << b << "\n";
    std::cout << "a.substr_all(c): " << "\n";
    int* buff = a.substr_all(c);
    idx = 0;
    while (buff[idx] != -1)
    {
        std::cout << buff[idx] << " ";
        ++idx;
    }
    std::cout << "\n";

    std::cout << "a.often(): " << a.often() << "\n";
    std::cout << "a.symbols(): " << "\n";
    char* buf = a.symbols();
    idx = 0;
    while (buf[idx] != 0)
    {
        std::cout << "\"" << buf[idx] << "\",";
        ++idx;
    }
    std::cout << "\n";
    std::cout << "a.symb_cnt(): " << "\n";
    idx = 0;
    int* ascii = a.symb_cnt();
    for (int i = 0; i < 256; ++i)
        if (ascii[i])
            std::cout << static_cast<char>(i) << ": " << ascii[i] << ", ";
    std::cout << "\n";
    std::cout << "Enter d: ";
    std::cin >> d;


    return 0;
}
