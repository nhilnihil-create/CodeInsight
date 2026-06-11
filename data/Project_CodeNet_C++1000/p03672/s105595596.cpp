#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

bool isEven(const string & s, int end)
{
    if (end % 2 != 0)
        return false;
    int middle = end / 2;
    for (int i = 0; i < middle; i++)
    {
        if (s[i] != s[middle + i])
            return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    for (int end = s.length() - 1; end > 0; end--)
    {
        if (isEven(s, end))
        {
            cout << end << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
