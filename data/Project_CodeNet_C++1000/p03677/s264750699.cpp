#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, m;
ll a[100005];
ll b[300005];
ll now;
ll ans;

int main()
{
    scanf("%lld%lld", &n, &m);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for(ll i = 0; i < n - 1; i++)
    {
        ll t1 = a[i];
        ll t2 = a[i + 1];
        if(t1 == t2) continue;
        if(t1 > t2) t2 += m;
        b[t1 + 2]--, b[t2 + 1]++;
        b[t2 + 1] += (t2 - t1 - 1);
        b[t2 + 2] -= (t2 - t1 - 1);
        t1 += m;
        t2 += m;
        b[t1 + 2]--, b[t2 + 1]++;
        b[t2 + 1] += (t2 - t1 - 1);
        b[t2 + 2] -= (t2 - t1 - 1);
    }
    for(ll i = 1; i <= 3 * m; i++)
    {
        b[i] += b[i - 1];
    }
    for(ll i = 0; i < n - 1; i++)
    {
        ll t1 = a[i + 1] - a[i];
        if(t1 < 0) t1 += m;
        if(a[i] > a[i + 1]) t1 = a[i + 1];
        now += t1;
    }
    ans = now;
    for(ll i = 2; i <= m; i++)
    {
        now += b[i + m];
        ans = min(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}
