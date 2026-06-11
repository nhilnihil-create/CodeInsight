#include <iostream>

using namespace std;

int main()
{
    int res = 0, val = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> val;
        if (val == 5 || val == 7)
        {
            res += val;
        }
        else
        {
            break;
        }
    }

    if (res == 17)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}