#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int INF = 1e9+10;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> cont(n-k+1);
    ll sum = 0;
    for(int i = 0; i < k; i++) sum += a[i];
    cont[0] = sum;
    for(int i = 1; i < n-k+1; i++)
    {
        sum -= a[i-1];
        sum += a[i+k-1];
        cont[i] = sum;
    }
    ll arb = 0;
    for(int i = k; i < n; i++)
    {
        if(a[i] > 0) arb += a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n-k+1; i++)
    {
        ll cand = arb;
        if(cont[i] > 0) cand += cont[i];
        ans = max(ans, cand);
        if(a[i] > 0) arb += a[i];
        if(a[i+k] > 0) arb -= a[i+k];
    }
    cout << ans << endl;
}
