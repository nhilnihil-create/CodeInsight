#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll INF = -4e18;
ll n, m;
ll u[2005], v[2005], w[2005];
ll a[1005];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= n; i++) a[i] = INF;
    a[1] = 0;
    for(ll i = 0; i < m; i++)
    {
        scanf("%lld%lld%lld", &u[i], &v[i], &w[i]);
    }
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            if(a[u[j]] != INF) if(a[v[j]] < a[u[j]] + w[j]) a[v[j]] = a[u[j]] + w[j];
        }
    }
    ll t = a[n];
    for(ll j = 0; j < m; j++)
    {
        if(a[u[j]] != INF) if(a[v[j]] < a[u[j]] + w[j]) a[v[j]] = a[u[j]] + w[j];
    }
    if(t < a[n])
    {
        printf("inf");
    }
    else
    {
        printf("%lld", a[n]);
    }
    return 0;
}

