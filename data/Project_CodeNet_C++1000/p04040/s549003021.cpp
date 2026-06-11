#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll H, W, ans = 0, A, B;

int main()
{
    COMinit();
    cin >> H >> W >> A >> B;
    for (ll i = 1; i <= H - A; i++)
    {
        ans += COM(i + B - 2, B - 1) * COM(W - B + H - i - 1, H - i);
        ans %= MOD;
    }
    cout << ans << endl;
}