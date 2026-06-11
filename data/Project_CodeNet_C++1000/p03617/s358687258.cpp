#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ll q, h, s, d;
    ll n;
    ll ans = 0;
    cin >> q >> h >> s >> d >> n;
    ll L = min({q * 4, 2 * h, s});
    ll L2 = min(L * 2, d);
    if (n % 2 == 0)
    {
        ans = L2 * n / 2;
    }
    else
    {
        ans = L2 * (n / 2) + L;
    }
    cout << ans << endl;

    return 0;
}