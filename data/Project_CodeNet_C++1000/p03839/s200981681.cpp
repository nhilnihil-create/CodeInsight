#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sum(n+1);
    vector<ll> posi(n+1);
    posi[0] = 0;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i-1];
        posi[i] = posi[i-1];
        if(a[i-1] > 0) posi[i] += a[i-1];
    }

    ll ans = 0;
    for(int i = 1; i <= n-k+1; i++)
    {
        ll tmp = posi[i-1] + posi[n] - posi[i+k-1];
        if(sum[i+k-1] - sum[i-1] > 0) tmp += sum[i+k-1] - sum[i-1];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
