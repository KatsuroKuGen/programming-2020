#include "iterator.h"
#include <string>
using namespace std;

int main() {
    int capacity, num;
    string command;

    cout << "enter the capacity:" << endl;
    cin >> capacity;
    Circular_Buffer<int> buff(capacity);

    cout << "enter the command (push; pop; stop) " << endl;
    cin >> command;

    while(command != "stop")
    {
        if(command == "push")
        {
            string push;
            cout << "enter the variant of push (top(push_top), back(push_back), yur(your variant); stop):" << endl;
            cin >> push;
            while (push != "stop")
            {
                if (push == "top")
                {
                    cout << "enter the elements:" << endl;
                    cin >> num;
                    buff.push_top(num);
                }

                else if (push == "back")
                {
                    cout << "enter the number:" << endl;
                    cin >> num;
                    buff.push_back(num);
                }

                else if (push == "yur")
                {
                    int n;
                    cout << "enter the number of element, which you want to add:" << endl;
                    cin >> n;
                    cout << "enter the number:" << endl;
                    cin >> num;
                    buff[n] = num;
                }
                cout << "enter the variant of push (top(push_top), back(push_back), yur(your variant); stop):" << endl;
                cin >> push;
            }
            for (int i : buff)
            {
                cout << i << " ";
            }
            cout << endl;
        }

        else if(command == "pop")
        {
            string push;
            cout << "enter the variant of pop (top(pop_top), back(pop_back)):" << endl;
            cin >> push;
            if(push == "top")
            {
                buff.pop_top();
            }
            else if(push == "back")
            {
                buff.pop_back();
            }
            for (int i : buff)
            {
                cout << i << " ";
            }
            cout << endl;
        }

        cout << "enter the command (push;  pop;  stop) " << endl;
        cin >> command;
    }

    return 0;
}
