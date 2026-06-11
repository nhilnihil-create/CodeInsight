#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
string str;
bool n = false, e = false, w = false, s = false;
int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'N')
            n = true;
        if (str[i] == 'W')
            w = true;
        if (str[i] == 'S')
            s = true;
        if (str[i] == 'E')
            e = true;
    }
    if (n & !s)
    {
        cout << "No" << endl;
        return 0;
    }
    if (s & !n)
    {
        cout << "No" << endl;
        return 0;
    }
    if (e & !w)
    {
        cout << "No" << endl;
        return 0;
    }
    if (w & !e)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}
