#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, k;
ll a[100005];
ll b[100005];
ll c[100005];
ll ans;
ll mn = 4e18;

int main()
{
    scanf("%lld%lld", &n, &k);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        if(a[i] > 0) ans += a[i];
    }
    for(ll i = 0; i < k; i++)
    {
        if(a[i] > 0) b[0] += a[i];
        else c[0] -= a[i];
    }
    mn = min(mn, min(b[0], c[0]));
    for(ll i = 1; i + k <= n; i++)
    {
        b[i] = b[i - 1];
        c[i] = c[i - 1];
        if(a[i - 1] > 0) b[i] -= a[i - 1];
        else c[i] += a[i - 1];
        if(a[i + k - 1] > 0) b[i] += a[i + k - 1];
        else c[i] -= a[i + k - 1];
        mn = min(mn, min(b[i], c[i]));
    }
    printf("%lld", -mn + ans);
    return 0;
}
