#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, m;
ll a[305][305];
bool v[305];
ll b[305];
ll cnt[305];
ll ans = 4e18;

int main()
{
    scanf("%lld%lld", &n, &m);
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            scanf("%lld", &a[i][j]);
        }
    }
    for(ll i = 0; i < m; i++)
    {
        ll mx = 0, mi = 0;
        for(ll j = 1; j <= m; j++)
        {
            cnt[j] = 0;
        }
        for(ll j = 0; j < n; j++)
        {
            cnt[a[j][b[j]]]++;
            if(mx < cnt[a[j][b[j]]]) mx = cnt[a[j][b[j]]], mi = a[j][b[j]];
        }
        ans = min(ans, mx);
        v[mi] = true;
        for(ll j = 0; j < n; j++)
        {
            while(v[a[j][b[j]]]) b[j]++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
