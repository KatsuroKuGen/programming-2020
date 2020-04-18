#include "3.1.h"
#include <iostream>
using namespace std;

Complex_num el_1(0,0);
Complex_num el_2(0, 0);
string command;

int main() {
    cout << "command list: ";
    cout << " [ push ]; [ show ]; [ * ]; [ + ]; [ len ]; [ stop ]; " << endl;
    cout << "(write all command without '[' ; ']') " << endl;

    while (command != "stop")
    {
        cout << "enter the command: " << endl;
        cin >> command;

        if (command == "push")
        {
            int num;
            cout << "enter the number of complex num (1 or 2): " << endl;
            cin >> num;
            if (num == 1)
            {
                el_1.push();
            }
            else
                {
                el_2.push();
            }
        }

        if (command == "show")
        {
            int num;
            cout << "enter the number of complex num (1 or 2): " << endl;
            cin >> num;
            if (num == 1)
            {
                el_1.show();
            }
            else if (num == 2)
                {
                el_2.show();
            }
        }

        if (command == "+")
        {
            (el_1 + el_2).show();
        }

        if (command == "*")
        {
            string additional_command;
            cout << "enter the command(re; complex_num):" << endl;
            cin >> additional_command;
            if (additional_command =="re")
            {
                double num;
                cout << "enter the real num which you want to multiplication:" << endl;
                cin >> num;
                (el_1 * num).show();
            }
            else
            {
                (el_1 * el_2).show();
            }
        }

        if (command == "len")
        {
            int num;
            cout << "enter the number of complex num (1 or 2): " << endl;
            cin >> num;
            if (command == "1")
            {
                cout << el_1.Length() << endl;
            }
            else
                {
                    cout << el_2.Length() << endl;
            }
        }
    }
    return 0;
}
