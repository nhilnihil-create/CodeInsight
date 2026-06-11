#include <iostream>
#include <cstdio>
#include <algorithm>
#define F first
#define S second
#define PLL pair<ll, ll>

using namespace std;

typedef long long ll;

ll mn = 4e18;
ll n;
PLL a[100005];
ll ans[100005];

int main()
{
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i].F);
        a[i].S = i;
    }
    sort(a + 1, a + n + 1, greater<PLL >());
    for(ll i = 1; i <= n; i++)
    {
        mn = min(mn, a[i].S);
        ans[mn] += i * (a[i].F - a[i + 1].F);
    }
    for(ll i = 1; i <= n; i++)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
