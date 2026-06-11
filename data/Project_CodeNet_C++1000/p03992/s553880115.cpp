#include <bits/stdc++.h>
using namespace std;
string str;
int main()
{
    cin >> str;
    for (int i = 0;i <= 3;i++)
    {
        cout << str[i];
    }
    cout << " ";
    for (int i = 4;i <= 11;i++)
    {
        cout << str[i];
    }
    cout << endl;
    return 0;
}