#pragma once
#include <cmath>
#include <iostream>


void strcpy(char dest[], const char source[]);

unsigned strlen(const char* str);

void strcat(char* to, const char* from);

class String
{
public:
    String(const char* str);

    String(char c);

    ~String();

    String(String& other);

    String(String& other, int i, int j);

    void append(String& other);

    String operator+(String& other);

    String& operator=(String const& other);

    bool operator==(String& other);

    bool operator<(String& other);

    bool operator>(String& other);

    friend std::istream& operator>>(std::istream& in, String& S);

    friend std::ostream& operator<<(std::ostream& out, String& S);

    char& operator[] (int idx);

    char* get_str();

    int get_size();

    int substr_first(String& other);

    int subsymb(char a);

    void dub_k(unsigned k);

    String* split(char c);

    int* substr_all(String& other);

    char often();

    char* symbols();

    int* symb_cnt();

private:
    char* str;

    int size;
};

std::istream& operator>>(std::istream& in, String& S);

std::ostream& operator<<(std::ostream& out, String& S);