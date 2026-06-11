#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll M = 1000000000;
ll n, p[20005];
ll a[20005], b[20005];
ll ans1[200005];
ll ans2[200005];

int main()
{
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        a[i] = i;
        b[i] = M - i + 1;
    }
    for(ll i = 1; i <= n; i++)
    {
        ans1[p[i]] += i - 1;
        ans2[p[i] + 1] -= i - 1;
    }
    for(ll i = 1; i <= n; i++)
    {
        ans1[i] += ans1[i - 1];
        ans2[i] += ans2[i - 1];
        a[i] += ans1[i];
        b[i] += ans2[i];
    }
    for(ll i = 1; i <= n; i++)
    {
        printf("%lld ", a[i]);
    }
    puts("");
    for(ll i = 1; i <= n; i++)
    {
        printf("%lld ", b[i]);
    }
    return 0;
}
