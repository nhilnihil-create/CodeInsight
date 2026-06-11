#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iomanip>
#include <float.h>
#include <math.h>
using namespace std;
using ll = long long;


unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

class UnionFind {
public:
    vector <ll> par;
    vector <ll> siz;
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    ll root(ll x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> z(n);
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    sort(z.begin(), z.end());
    reverse(z.begin(), z.end());
    ll flag = 0;
    double ans = 0;
    for (int i = 0; i < a; i++) {
        if (z[0] != z[i])flag = 1;
        ans += z[i];
    }
    ans = 1.0 * ans / a;
    cout << fixed << setprecision(15) << ans << endl;
    if (flag == 0) {
        ll h = 0;
        for (int i = 0; i < n; i++) {
            if (z[0] != z[i])break;
            h = i+1;
        }
        vector<ll> dp(n + 10);
        dp[0] = 1;
        for (int i = 0; i < h; i++) {
            vector<ll> a(n + 10);
            for (int j = 0; j < n+5; j++) {
                a[j] = dp[j];
                dp[j] = 0;
            }
            for (int j = 0; j < n+5; j++) {
                dp[j] += a[j];
                dp[j + 1] += a[j];
            }
        }
        ll bb = 0;
        for (int i = a; i <= min(h,b); i++) {
            bb += dp[i];
        }
        cout << bb << endl;
    }
    else {
        ll mn = 10000;
        ll mx = 0;
        for (ll i = 0; i < n; i++) {
            if (z[i] == z[a - 1]) {
                mn = min(mn, i);
                mx = max(mn, i);
            }
        }
        vector<ll> dp(n+10);
        dp[0] = 1;
        for (int i = 0; i < mx-mn+1; i++) {
            vector<ll> a(n + 10);
            for (int j = 0; j < n+5; j++) {
                a[j] = dp[j];
                dp[j] = 0;
            }
            for (int j = 0; j < n+5; j++) {
                dp[j] += a[j];
                dp[j + 1] += a[j];
            }
        }
        cout << dp[a - mn] << endl;
    }

}