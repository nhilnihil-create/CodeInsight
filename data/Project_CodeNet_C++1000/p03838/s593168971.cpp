#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    ll x, y;
    cin >> x >> y;
    ll ay = abs(y);
    ll ax = abs(x);
    if(x < y)
    {
        if(x * y >= 0)
        {
            cout << abs(ay - ax) << endl;
        }
        else
        {
            cout << abs(ay-ax) + 1 << endl;
        }
    }
    else
    {
        if(x * y > 0)
        {
            cout << abs(ay - ax) + 2 << endl;
        }
        else
        {
            cout << abs(ay-ax) + 1 << endl;
        }
    }
}
