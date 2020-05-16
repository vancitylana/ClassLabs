#pragma once
#include <cmath>
#include <iostream>

class Complex
{
public:
    Complex();

    Complex(double re, double im);

    Complex(Complex& other);

    Complex operator+(Complex const& other) const;

    Complex operator-(Complex const& other) const;

    Complex operator*(Complex const& other) const;

    Complex operator/(Complex const& other) const;

    Complex& operator=(Complex const& other);

    bool operator==(Complex const& other);

    friend std::ostream& operator<<(std::ostream& out, Complex const& val);

    friend std::istream& operator>>(std::istream& in, Complex& val);

    double get_real_part() const;

    double get_imaginary_part() const;

    double module();

    double pow(Complex x);

    void print_trig(std::ostream& out);

private:
    double re_;

    double im_;
};

std::ostream& operator<<(std::ostream& out, Complex const& val);

std::istream& operator>>(std::istream& in, Complex& val);
