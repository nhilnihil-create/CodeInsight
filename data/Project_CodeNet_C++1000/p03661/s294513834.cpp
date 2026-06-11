#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
const ll INF = 1e14;
const ll MOD = 1e9 + 7;
int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    ll sum = 0, x = 0, ans = INF;
    rep(i, N)
    {
        cin >> a[i];
        sum += a[i];
    }
    rep(i, N)
    {
        x += a[i];
        if (i < N - 1) {
            ans = min(ans, abs(sum - 2 * x));
        }
    }
    cout << ans << endl;
    return 0;
}