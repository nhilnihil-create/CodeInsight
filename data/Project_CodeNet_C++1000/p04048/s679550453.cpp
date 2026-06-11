#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll ans = 0;

void gcd (ll a, ll b)
{
    if(b == 0)
    {
        ans -= a;
        return;
    }
    if(a >= b)
        ans += b * (a / b) * 2;
    gcd(b, a % b);
}

ll n, x;

int main()
{
    cin >> n >> x;
    gcd(n - x, x);
    cout << ans + n << "\n";
    return 0;
}
