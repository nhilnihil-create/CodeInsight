#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;
ll n, mx = -4e18;
ll a[300005];
ll b[300005];
ll c[300005];
priority_queue<ll> pq2;
priority_queue<ll, vector<ll>, greater<ll> > pq1;

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n * 3; i++)
    {
        scanf("%lld", &a[i]);
    }
    for(ll i = 0; i < n; i++)
    {
        pq1.push(a[i]);
        b[n - 1] += a[i];
    }
    for(ll i = n; i < n * 3; i++)
    {
        b[i] = b[i - 1] + a[i];
        pq1.push(a[i]);
        b[i] -= pq1.top();
        pq1.pop();
    }
    for(ll i = 0; i < n; i++)
    {
        ll j = n * 3 - 1 - i;
        pq2.push(a[j]);
        c[n * 2] += a[j];
    }
    for(ll i = n; i < n * 3; i++)
    {
        ll j = n * 3 - 1 - i;
        c[j] = c[j + 1] + a[j];
        pq2.push(a[j]);
        c[j] -= pq2.top();
        pq2.pop();
    }
    for(ll i = n - 1; i < n * 2; i++)
    {
        mx = max(mx, b[i] - c[i + 1]);
    }
    printf("%lld", mx);
    return 0;
}
