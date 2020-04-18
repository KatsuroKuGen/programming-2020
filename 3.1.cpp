#include "third.1.h"
#include <iostream>
using namespace std;

complex_num el_1("complex_num_1");
complex_num el_2("complex_num_2");
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
                el_1.push("complex_num_1");
            }
            else
                {
                el_2.push("complex_num_2");
            }
        }

        if (command == "show")
        {
            int num;
            cout << "enter the number of complex num (1 or 2): " << endl;
            cin >> num;
            if (num == 1)
            {
                el_1.show("complex_num_1");
            }
            else
                {
                el_2.show("complex_num_2");
            }

        }

        if (command == "+")
        {
            el_1 + el_2;
        }

        if (command == "*")
        {
            el_1 * el_2;
        }

        if (command == "len")
        {
            int num;
            double result;
            cout << "enter the number of complex num (1 or 2): " << endl;
            cin >> num;
            if (command == "1")
            {
                result = el_1 ^ el_1;
                cout << result << endl;
            } else
                {
                result = el_2 ^ el_2;
                cout << result << endl;
            }
        }
    }
    return 0;
}
