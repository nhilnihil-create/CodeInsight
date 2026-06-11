#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int MAX = 110000;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

ll modpow(ll a, ll n, ll MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];

    ll xsum = 0;
    rep(i, n-1) {
        int j = i + 1;
        xsum += (x[j]-x[i]) * (i+1) % MOD * (n-j) % MOD;
        xsum %= MOD;
    }

    ll ysum = 0;
    rep(i, m-1) {
        int j = i + 1;
        ysum += (y[j]-y[i]) * (i+1) % MOD * (m-j) % MOD;
        ysum %= MOD;
    }

    ll ans = xsum * ysum % MOD;
    cout << ans << endl;


    return 0;
}
