#include "sixth.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<Point> points;
    vector<int> arr;
    string command, vector;
    int len;
    int x, y, num;

    cout << "enter the command (push; any_of; is_partitioned; is_palindrome; stop) " << endl;
    cout << "only the (any of) command works for the point vector):" << endl;
    cin >> command;

    while(command != "stop")
    {
        if(command == "push")
        {
            cout << "enter the select the vector type (p(vector<Point>); arr):" << endl;
            cin >> vector;
            if(vector == "p")
            {
                cout << "enter the len of vector with points: " << endl;
                cin >> len;

                for(int i = 0; i < len; i++)
                {
                    cout << "enter the coordinates of the point (x, y):" << endl;
                    cin >> x >> y;
                    points.push_back(Point(x,y));
                }
            }
            else if(vector =="arr")
            {
                cout << "enter the len of vector with points: " << endl;
                cin >> len;

                for(int i = 0; i < len; i++)
                {
                    cout << "enter the number:" << endl;
                    cin >> num;
                    arr.push_back(num);
                }
            }
            cout << "==================================================================================" << endl;
        }

        else if(command == "any_of")
        {
            cout << "enter the select the vector type (p(vector<Point>); arr):" << endl;
            cin >> vector;
            if(vector == "p")
            {
                cout << "this vector with points " << (any_of(points, Comparator()) ? "" : "don't ") << "have a Point(0;0) " << endl;
                cout << "==================================================================================" << endl;
            }

            else if(vector =="arr")
            {
                cout << "this array " << (any_of(arr, IsEven()) ? "is " : "isn't ") << "even" << endl;
                cout << "==================================================================================" << endl;
            }
        }

        else if (command == "is_partitioned")
        {
            cout << "this array " << (is_partitioned(arr.begin(), arr.end(), IsOdd()) ? "is a" : "isn't a ") << "partitioned" << endl;
            cout << "==================================================================================" << endl;
        }

        else if (command == "is_palindrome")
        {
            cout << "this array " << (is_palindrome(arr, is_equals<int>) ? "is a" : "isn't a") << "partitioned" << endl;
            cout << "==================================================================================" << endl;
        }

        cout << "enter the command (push; any_of; is_partitioned; is_palindrome; stop) " << endl;
        cout << "only the (any of) command works for the point vector):" << endl;
        cin >> command;
    }

    return 0;
}
#include "sixth.h"
