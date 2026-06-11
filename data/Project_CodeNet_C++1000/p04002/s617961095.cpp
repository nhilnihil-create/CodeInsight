#include <iostream>
#include <cstdio>
#include <map>
#define F first
#define S second

using namespace std;

typedef long long ll;

ll h, w, n;
ll a[15];
map<pair<ll, ll>, ll> ma;

int main()
{
    scanf("%lld%lld%lld", &h, &w, &n);
    for(ll i = 0; i < n; i++)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        for(ll j = -2; j <= 0; j++)
        {
            for(ll k = -2; k <= 0; k++)
            {
                if(x + j < 1 || y + k < 1) continue;
                if(x + j + 2 > h || y + k + 2 > w) continue;
                ma[make_pair(x + j, y + k)]++;
            }
        }
    }
    for(auto it : ma)
    {
        a[it.S]++;
    }
    a[0] = (h - 2) * (w - 2);
    for(ll i = 1; i <= 9; i++)
    {
        a[0] -= a[i];
    }
    for(ll i = 0; i <= 9; i++)
    {
        printf("%lld\n", a[i]);
    }
    return 0;
}
