#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x;

ll Get(ll x, ll y)
{
    if (x < y) return Get(y, x);
    if (y == 0) return 0;
    ll d = x / y;
    return 3ll * d * y + Get(y, x % y);
}

int main()
{
    cin >> n >> x;
    printf("%lld\n", Get(x, n - x));
    return 0;
}
