#include "String.h"

void strcpy(char dest[], const char source[])
{
    int i = 0;
    while (1)
    {
        dest[i] = source[i];
        if (dest[i] == '\0')
            break;
        i++;
    }
}

unsigned strlen(const char* str)
{
    unsigned res = 0;
    for (; *str != '\0'; ++str, ++res)
    {
    }
    return res;
}

void strcat(char* to, const char* from)
{
    char* p;
    for (p = to; *p != '\0'; ++p)
    {
    }
    for (int i = 0; from[i] != '\0'; ++i)
    {
        *p = from[i];
        ++p;
    }
    *p = '\0';
}

String::String(const char* str = "") : size(strlen(str))
{
    this->str = new char[size + 1];
    strcpy(this->str, str);
}

String::String(char c) : size(1)
{
    this->str = new char[size + 1];
    str[0] = c;
}

String::~String()
{
    delete[] str;
}

String::String(String& other) : String(other.str)
{
}

String::String(String& other, int i, int j) : size(j - i)
{

    str = new char[size + 1];
    for (int p = 0; p < size; ++p)
        str[p] = other.str[i + p];
}

void String::append(String& other)
{
    int mysz = size;
    char* fr = new char[size + 1];
    char* fro = new char[other.size + 1];
    strcpy(fr, str);
    strcpy(fro, other.str);
    size += other.size;
    delete[] str;
    str = new char[size + 1];
    strcpy(str, fr);
    strcpy(str + mysz, fro);
    delete[] fr;
    delete[] fro;
}

String String::operator+(String& other)
{
    String res("");
    res.append(*this);
    res.append(other);
    return res;
}

String& String::operator=(String const& other)
{
    if (&other == this)
        return *this;

    delete[] str;
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
    return *this;
}

bool String::operator==(String& other)
{
    if (size != other.size)
        return 0;
    for (int i = 0; i < size; ++i)
        if (str[i] != other.str[i])
            return 0;
    return 1;
}

bool String::operator<(String& other)
{
    if (*this == other)
        return 0;
    int sz = other.size < size ? other.size : size;
    for (int i = 0; i <= sz; ++i)
        if (str[i] != other.str[i])
            return str[i] < other.str[i];
    return 0;
}

bool String::operator>(String& other)
{
    if (*this == other)
        return 0;
    return !(*this < other);
}

char& String::operator[](int idx)
{
    return str[idx];
}

char* String::get_str()
{
    return str;
}

int String::get_size()
{
    return size;
}

int String::substr_first(String& other)
{
    for (int i = 0; i <= size - other.size; ++i)
    {
        int fl = 1;
        for (int p = 0; p < other.size; ++p)
        {
            if (str[i + p] != other.str[p])
            {
                fl = 0;
                break;
            }
        }
        if (fl)
            return i;
    }
    return -1;
}

int String::subsymb(char a)
{
    String buf(a);
    return substr_first(buf);
}

void String::dub_k(unsigned k)
{
    String buf = *this;
    while (k)
    {
        append(buf);
        --k;
    }
}

String* String::split(char c)
{
    String* to_cpy = new String[size];
    int idx = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j <= size; ++j)
        {
            if (str[j] == c || str[j] == 0)
            {
                String buff = String(*this, i, j);
                to_cpy[idx] = buff;
                idx++;
                i = j;
                break;
            }
        }
    }
    String* res = new String[idx + 1];
    String termin("TERMINAL_ERR");
    termin.size = -1;
    for (int i = 0; i < idx; ++i)
        res[i] = to_cpy[i];
    res[idx] = termin;
    delete[] to_cpy;
    return res;
}

int* String::substr_all(String& other)
{
    int* to_cpy = new int[size];
    int idx = 0;
    for (int i = 0; i <= size - other.size; ++i)
    {
        int fl = 1;
        for (int p = 0; p < other.size; ++p)
        {
            if (str[i + p] != other.str[p])
            {
                fl = 0;
                break;
            }
        }
        if (fl)
        {
            to_cpy[idx] = i;
            ++idx;
        }
    }
    int* res = new int[idx + 1];
    for (int i = 0; i < idx; ++i)
        res[i] = to_cpy[i];
    res[idx] = -1;
    delete[] to_cpy;
    return res;
}

char String::often()
{
    int* ascii = new int[256];
    for (int i = 0; i < 256; ++i)
        ascii[i] = 0;
    for (int i = 0; i < size; ++i)
        ascii[str[i]]++;
    int max = 0;
    for (int i = 0; i < 256; ++i)
        max = max > ascii[i] ? max : ascii[i];
    char res;
    for (int i = 0; i < 256; ++i)
        if (ascii[i] == max)
            res = i;
    delete[] ascii;
    return res;
}

char* String::symbols()
{
    char* to_cpy = new char[256];
    int* ascii = new int[256];
    for (int i = 0; i < 256; ++i)
        ascii[i] = 0;
    for (int i = 0; i < size; ++i)
        ascii[str[i]]++;
    int idx = 0;
    for (int i = 0; i < 256; ++i)
        if (ascii[i])
        {
            to_cpy[idx] = i;
            ++idx;
        }

    char* res = new char[idx + 1];
    for (int i = 0; i < idx; ++i)
        res[i] = to_cpy[i];
    res[idx] = 0;
    delete[] to_cpy;
    return res;
}

int* String::symb_cnt()
{
    int* ascii = new int[256];
    for (int i = 0; i < 256; ++i)
        ascii[i] = 0;
    for (int i = 0; i < size; ++i)
        ascii[str[i]]++;
    return ascii;
}

std::istream& operator>>(std::istream& in, String& S)
{
    delete[] S.str;
    S.str = new char[51];
    in.getline(S.str, 50);
    S.size = strlen(S.str);
    return in;
}

std::ostream& operator<<(std::ostream& out, String& S)
{
    for (int i = 0; i < S.size; ++i)
        std::cout << S.str[i];
    return out;
}