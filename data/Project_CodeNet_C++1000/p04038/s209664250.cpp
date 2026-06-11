#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
const int MAXN = 2000*2000;
long long kai[MAXN+1];
long long inv[MAXN+1];
long long mod = 1e9+7;
long long mp(long long a, long long b) {
    long long res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}
void init() {
    kai[0] = 1;
    for (long long i = 1; i <= MAXN; i++) kai[i] = kai[i - 1] * i % mod;
    inv[MAXN] = mp(kai[MAXN], mod-2);
    for (long long i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i % mod;
}
long long calc(long long n, long long k) {
    if (n < k) return 0;
    return (kai[n] * inv[k]) % mod * inv[n - k] % mod;
}

ll dp[2010][2010];
bool ok[2010][2010];

ll dfs(int a, int b) {
    if (ok[a][b]) return dp[a][b];
    ll ret = 0;
    if (a - 1 >= 0) ret += dfs(a-1,b);
    if (b - 1 >= a) ret += dfs(a, b-1) * calc(a + b * (k - 1) - 1, k - 2) % mod;
    ok[a][b] = 1;
    return dp[a][b] = ret % mod;
}

int main() {
    cin >> n >> k;
    init();
    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    dp[0][0] = 1;
    ok[0][0] = 1;
    ll ret = dfs(n,n);
    for (ll i = 1; i <= n; i++) ret = ret * i % mod;
    cout << ret << endl;
    return 0;
}