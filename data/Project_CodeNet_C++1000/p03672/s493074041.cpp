#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define P 1000000007
#define inf 1e18
int main()
{
    ll i, n;
    string s;
    cin >> s;
    n = s.length();

    for (i = s.length() % 2 == 0 ? 2 : 1; i < n; i = i + 2)
    {
        string t;
        for (ll j = 0; j < n - i; j++)
            t = t + s[j];
        ll len = t.length();
        string t1 = t.substr(0, len / 2);
        string t2 = t.substr(len / 2, len / 2);
        if (t1 == t2)
        {
            cout << len << "\n";
            exit(0);
        }
    }

    return (0);
}