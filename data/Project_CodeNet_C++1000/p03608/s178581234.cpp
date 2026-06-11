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
    ll n, m, r;
    cin >> n >> m >> r;
    vector<ll> oto(r);
    for (int i = 0; i < r; i++) {
        cin >> oto[i];
        oto[i]--;
    }
    vector<vector<ll>> miti(n,vector<ll>(n,1000000000));
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        miti[a - 1][b - 1] = c;
        miti[b - 1][a - 1] = c;
    }
    vector<vector<ll>> michi(r, vector<ll>(r,1000000000));
    for (int i = 0; i < r; i++) {
        vector<ll> tan(n,1000000000);
        vector<bool> seen(n, false);
        tan[oto[i]] = 0;
        while (true) {
            ll v = -1;
            for (int j = 0; j < n; j++) {
                if (seen[j] == false && (v == -1 || tan[j] < tan[v]))v = j;
            }
            if (v == -1)break;
            
            seen[v] = true;
            for (int j = 0; j < n; j++) {
                tan[j] = min(tan[j], tan[v] + miti[v][j]);
            }
            
        }
        for (int j = 0; j < r; j++) {
            if (i != j)michi[i][j] = tan[oto[j]];
        }
    }
    vector<ll> array(r);
    for (int i = 0; i < r; i++) {
        array[i] = i;
    }
    ll ans = 1000000000;
    do {
        ll zans = 0;
        for (int i = 0; i < r-1; i++) {
            zans += michi[array[i]][array[i + 1]];
        }
        ans = min(ans, zans);
    } while (next_permutation(array.begin(), array.end()));
    cout << ans << endl;
}