#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const int mod = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int a = -1, b = -1;
    for (int i = 1; i < n; i++)
    {
        if (s.at(i - 1) == s.at(i))
        {
            a = i;
            b = i + 1;
            break;
        }
        if (i > 1 && s.at(i) == s.at(i - 2))
        {
            a = i - 1;
            b = i + 1;
            break;
        }
    }

    cout << a << ' ' << b << endl;
    return 0;
}