#include "fith_C.h"
#include <iostream>
using namespace std;

int main()
{
    int int_1, int_2;
    char char_1, char_2;
    string command;

    cin >> command;

    if(command =="1")
    {
        cin >> int_1 >> int_2;
        cout << "before swap: " << int_1 << " " << int_2 << endl;
        swap_elements<int>(int_1, int_2);
        cout << "after swap: " << int_1 << " " << int_2;
    }
    else
    {
        cin >> char_1 >> char_2;
        cout << "before swap: " << char_1 << " " << char_2 << endl;
        swap_elements<char>(char_1, char_2);
        cout << "after swap: " << char_1 << " " << char_2;
    }
}
