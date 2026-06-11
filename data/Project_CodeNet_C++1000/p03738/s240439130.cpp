#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "EQUAL" << endl;
        return 0;
    }
    if (a.size() != b.size())
    {
        if (a.size() > b.size())
        {
            cout << "GREATER" << endl;
            return 0;
        }
        else
        {
            cout << "LESS" << endl;
            return 0;
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a.at(i) > b.at(i))
        {
            cout << "GREATER" << endl;
            return 0;
        }
        else
        {
            cout << "LESS" << endl;
            return 0;
        }
    }
}