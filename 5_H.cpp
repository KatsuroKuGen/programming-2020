#include "fith_H.h"
int main()
{
    matrix<int, 3, 3> element;

    try
    {
        element.check(1, 1);
    }
    catch (MyException e)
    {
        cout << e.getError() << endl;
    }
}
