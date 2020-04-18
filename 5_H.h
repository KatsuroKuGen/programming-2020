#ifndef LAB_1_FITH_H_H
#define LAB_1_FITH_H_H
#include <iostream>
#include <exception>
#include <utility>
using namespace std;

class MyException : public exception
{
    string msg;
public:
    MyException(string msg) : msg(std::move(msg)) {}

    const string& getError() const
    {
        return msg;
    }
};

template <typename type, int N, int M>
class matrix
{
public:

    type mat[N][M];

    matrix ()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                type symbol;

                cout << "Enter the value (" << i << "," << j << ")" << endl;
                cin >> symbol;

                mat[i][j] = symbol;
            }
        }
    }

    void check(int i, int j)
    {
        if (i >= N || j >= M || i < 0 || j < 0)
        throw MyException("Out of range");
        cout << "(" << i << "," << j << ") = " << this->mat[i][j] << endl;
    }

    ~matrix()
    {
        for (int i = 0; i < N; i++)
        {
            delete []mat[i];
        }
    }
};
#endif //LAB_1_FITH_H_H
