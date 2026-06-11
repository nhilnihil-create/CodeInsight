#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
ll H, W, A, B;

// Combination
const ll COMB_MAX = 1e6;
ll fac[COMB_MAX], finv[COMB_MAX], inv[COMB_MAX];
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < COMB_MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main()
{
    cin >> H >> W >> A >> B;
    ll ans = 0;
    COMinit();

    for (ll x = B; x < W; ++x) {
        ll w1 = x;
        ll h1 = (H - A - 1);
        ll sum1 = COM(w1 + h1, w1);
        ll w2 = W - w1 - 1;
        ll h2 = A - 1;
        ll sum2 = COM(w2 + h2, w2);
        ans += (sum1 * sum2) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}