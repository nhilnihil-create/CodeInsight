#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll M = 4e18;
ll n, x, y;
ll d[405][405];

int main()
{
    scanf("%lld%lld%lld", &n, &x, &y);
    for(ll i = 0; i <= 400; i++)
    {
        for(ll j = 0; j <= 400; j++)
        {
            d[i][j] = M;
        }
    }
    d[0][0] = 0;
    for(ll i = 0; i < n; i++)
    {
        ll t1, t2, t3;
        scanf("%lld%lld%lld", &t1, &t2, &t3);
        for(ll j = 400; j >= t1; j--)
        {
            for(ll k = 400; k >= t2; k--)
            {
                d[j][k] = min(d[j][k], d[j - t1][k - t2] + t3);
            }
        }
    }
    ll ans = M;
    for(ll i = x, j = y; i <= 400 && j <= 400; i += x, j += y)
    {
        ans = min(ans, d[i][j]);
    }
    if(ans == M) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}
