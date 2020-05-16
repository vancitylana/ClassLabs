#include "complex.h"

Complex::Complex() : re_(0), im_(0)
{
}

Complex::Complex(double re, double im) : re_(re), im_(im)
{
}

Complex::Complex(Complex& other) : re_(other.re_), im_(other.im_)
{
}

Complex Complex::operator+(Complex const& other) const
{
    return Complex(re_ + other.re_, im_ + other.im_);
}

Complex Complex::operator-(Complex const& other) const
{
    return Complex(re_ - other.re_, im_ - other.im_);
}

Complex Complex::operator*(Complex const& other) const
{
    return Complex(re_ * other.re_ - im_ * other.im_, re_ * other.im_ + other.re_ * im_);
}

Complex Complex::operator/(Complex const& other) const
{
    return Complex(((re_ * other.re_ + im_ * other.im_) / (other.re_ * other.re_ + other.im_ * other.im_)), ((im_ * other.re_ - re_ * other.im_) / (other.re_ * other.re_ + other.im_ * other.im_)));
}

Complex& Complex::operator=(Complex const& other)
{
    re_ = other.re_;
    im_ = other.im_;
    return *this;
}

bool Complex::operator==(Complex const& other)
{
    return ((re_ == other.re_) && (im_ == other.im_));
}

double Complex::get_real_part() const
{
    return re_;
}
double Complex::get_imaginary_part() const
{
    return re_;
}

double Complex::module()
{
    return std::sqrt(re_ * re_ + im_ * im_);
}

double Complex::pow(Complex x)
{
    double fi = std::atan2(im_ / module(), re_ / module());
    Complex ln_part(std::log(module()), fi);
    Complex product = ln_part * x;
    Complex exp_form(std::exp(product.re_) * std::cos(product.im_), std::exp(product.re_) * std::sin(product.im_));
    re_ = exp_form.re_;
    im_ = exp_form.im_;
    return 0;
}

void Complex::print_trig(std::ostream& out)
{
    double fi = std::atan2(im_ / module(), re_ / module());
    out << module() << "*(cos(" << fi << ") + i*sin(" << fi << "))";
    return;
}

std::ostream& operator<<(std::ostream& out, Complex const& val)
{
    out << val.re_ << "+" << val.im_ << "i";
    return out;
}
std::istream& operator>>(std::istream& in, Complex& val)
{
    char buf;
    in >> val.re_ >> buf >> val.im_ >> buf;
    return in;
}
