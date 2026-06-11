#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, k;
ll a[200005];
ll b[200005];
ll d[200005];
ll ans;
vector<ll> ve;

void f(ll p)
{
    while(p <= n)
    {
        d[p]++;
        p += (p & (-p));
    }
}

ll g(ll p)
{
    ll re = 0;
    while(p > 0)
    {
        re += d[p];
        p -= (p & (-p));
    }
    return re;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    b[0] = 1;
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] -= k;
        b[i] = b[i - 1] + a[i];
        ve.push_back(b[i]);
    }
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    for(ll i = 0; i <= n; i++)
    {
        b[i] = lower_bound(ve.begin(), ve.end(), b[i]) - ve.begin() + 1;
        ans += g(b[i]);
        f(b[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
