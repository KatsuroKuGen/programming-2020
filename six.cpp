#include "six.h"
#include <vector>
#include <map>

int main()
{
    string command;
    vector<int> my_vector = {1, 3, 5, 7, 9};
    map<int, vector<int>> my_map ={{1, {1, 3, 5, 3, 1}},
                                   {2, {1, 2, 3}},
                                   {3, {1, -228, 5}}};

    while (command != "stop")
    {
        cout << endl << "Enter the command: " << endl;
        cin >> command;

        if (command == "all_of")
        {
            if(all_of(my_vector.begin(), my_vector.end(), predicate_all_of))
            {
                cout << "All elements in my vector more then -288" << endl;
            }
            else
            {
                cout << "Some elements in my vector less then -288" << endl;
            }

            for(auto i = my_map.begin(); i != my_map.end(); ++i)
            {
                if(all_of(i->second.begin(), i->second.end(), predicate_all_of))
                {
                    cout << "in key: " << i->first << " All elements more then -288" << endl;
                }
                else
                {
                    cout << "in key: " << i->first << " Some elements less then -288" << endl;
                }
            }

            continue;
        }

        if (command == "is_sorted")
        {
            if(is_sorted(my_vector.begin(), my_vector.end(), sorting_criteria))
            {
                cout << "My_vector is sorted" << endl;
            }
            else
            {
                cout << "My_vector not sorted" << endl;
            }

            for(auto i = my_map.begin(); i != my_map.end(); ++i)
            {
                if(is_sorted(i->second.begin(), i->second.end(), sorting_criteria))
                {
                    cout << "in key: " << i->first << " vector is sorted" << endl;
                }
                else
                {
                    cout << "in key: " << i->first << " vector not sorted" << endl;
                }
            }

            continue;
        }
        if (command == "is_palindrome")
        {
            if(is_palindrome(my_vector.begin(), my_vector.end(), palindrome_criteria))
            {
                cout << "My_vector is palindrome" << endl;
            }
            else
            {
                cout << "My_vector not palindrome" << endl;
            }

            for(auto i = my_map.begin(); i != my_map.end(); ++i)
            {
                if(is_palindrome(i->second.begin(), i->second.end(), palindrome_criteria))
                {
                    cout << "in key: " << i->first << " vector is palindrome" << endl;
                }
                else
                {
                    cout << "in key: " << i->first << " vector not palindrome" << endl;
                }
            }
        }
    }
}
