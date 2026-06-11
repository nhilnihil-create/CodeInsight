#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2000;
const ll INF = 1e16;
ll a[MAXN + 5], m[MAXN + 5];

int main()
{
    ll n, x;
    cin >> n >> x;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i] = a[i];
        ans += a[i];
    }
    for (ll k = 1; k <= n - 1; k++)
    {
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            m[i] = min(m[i], a[(i - k + n) % n]);
            sum += m[i];
        }
        ans = min(ans, sum + x * k);
    }
    cout<<ans;
}