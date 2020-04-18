#ifndef LAB_1_THIRD_1_H
#define LAB_1_THIRD_1_H
#include<iostream>
#include <cmath>
using namespace std;

class complex_num {
private:
    double im;
    double re;

public:
    complex_num(string name){}

    void push(string name)
    {
        cout << "enter the real number for " << name << endl;
        cin >> this->re;
        cout << "enter the imaginary number for " << name << endl;
        cin >> this->im;
    }

    void show(string name)
    {
        if(im >= 0)
        {
            cout << name << " = " << this->re << "+" << this->im << "i" << endl;
        }

        else if(im < 0)
        {
            cout << name << " = " << this->re << this->im << "i" << endl;
        }
    }

    double operator^(complex_num name)
    {
        double a;
        a = sqrt(pow(this ->im, 2) + pow(this->re, 2));
        return a;
    }

    void operator*(complex_num &a)
    {
        string command;
        cout << "enter the command(re; complex_num):";
        cin >> command;
        if (command == "re")
        {
            int num;
            cout << "enter the real num which you want to multiplication: " << endl;
            cin >> num;
            this->re = this->re * num;
            this->im = this->im * num;
        }
        if (command =="complex_num")
        {
            this->re = this->re*a.re - this->im * a.im;
            this->im = this->im*a.re + this->re * a.im;
            cout << "complete" << endl;
        }
    }

    void operator+(complex_num &a)
    {
        this->re = this->re + a.re;
        this->im = this->im + a.im;
        cout << "complete" << endl;
    }
};
#endif //LAB_1_THIRD_1_H
