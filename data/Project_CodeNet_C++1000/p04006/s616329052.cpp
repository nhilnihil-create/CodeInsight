#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define all(obj) (obj).begin(), (obj).end()
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
ll N, x;

signed main()
{
    cin >> N >> x;
    vector<ll> a(N), b(N);

    ll ans = 0;
    rep(i, N)
    {
        cin >> a[i];
        b[i] = a[i];
        ans += a[i];
    }

    rep(k, N) // 魔法を唱える数(固定)
    {
        ll cost = k * x;
        rep(i, N)
        {
            b[i] = min(b[i], a[(i - k + N) % N]);
        }
        rep(i, N)
        {
            cost += b[i];
        }
        ans = min(ans, cost);
    }

    cout << ans << endl;

    return 0;
}