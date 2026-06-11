#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (a % b == 0)
        return b;
    return gcd(a % b, b);
}

int main()
{
    ll n, k;
    cin >> n >> k;
    ll m = 0, g = 0;
    //0と任意の数nとのGCDはn

    rep(i, n)
    {
        ll a;
        cin >> a;
        g = gcd(a, n);
        m = max(m, a);
    }

    if (k <= m && k % g == 0)
    {
        cout << "POSSIBLE" << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}