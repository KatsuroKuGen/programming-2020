#ifndef LAB_1_3_1_H
#define LAB_1_3_1_H
#include<iostream>
#include <cmath>

class Complex_num{
private:
    double im;
    double re;

public:
    Complex_num(double re, double im): re(re), im(im){}

    void push()
    {
        std::cout << "enter the real number for your complex_num "  << std::endl;
        std::cin >> this->re;
        std::cout << "enter the imaginary number for your complex_num " << std::endl;
        std::cin >> this->im;
    }

    void show()
    {
        if(im >= 0)
        {
            std::cout << "complex_num = " << this->re << "+" << this->im << "i" << std::endl;
        }

        else if(im < 0)
        {
            std::cout << "complex_num = " << this->re << this->im << "i" << std::endl;
        }
    }

    double Length()
    {
        return sqrt(this->re * this->re + this->im * this->im);
    }

    operator double()
    {
        return this->Length();
    }

    Complex_num operator*(const double num)
    {
        return Complex_num(this->re * num, this->im * num);
    }

    Complex_num operator*(const Complex_num &a)
    {
        return Complex_num(this->re * a.re - this->im * a.im, this->re * a.im + this->im * a.re);
    }

    Complex_num operator+(Complex_num &a)
    {
        return Complex_num(this->re + a.re, this->im + a.im);
    }
};
#endif //LAB_1_3_1_H
