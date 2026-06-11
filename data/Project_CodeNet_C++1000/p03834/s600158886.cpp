#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    string s;
    for (int i = 0; i < 19; i++)
    {
        char c;
        cin >> c;
        if (c == ',')
        {
            s += ' ';
        }
        else
        {
            s += c;
        }
    }
    cout << s << endl;

    return 0;
}