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
    ll n,m;
    cin >> n >> m;
    vector<pair<pair<ll,ll>,ll>> z(m);
    for (int i = 0; i < m; i++) {
        cin >> z[i].first.first >> z[i].first.second >> z[i].second;
        z[i].first.first--;
        z[i].first.second--;
    }
    vector<ll> point(n, -100000000000000000);
    point[0] = 0;
    for (int iii = 0; iii < n; iii++) {
        for (int i = 0; i < m; i++) {
            point[z[i].first.second] = max(point[z[i].first.second], point[z[i].first.first] + z[i].second);
        }
    }
    ll a = 0;
    for (int iii = 0; iii < n+5; iii++) {
        for (int i = 0; i < m; i++) {
            if (point[z[i].first.second] < point[z[i].first.first] + z[i].second && z[i].first.second == n - 1) {
                a = -1000000000000000000;

            }
            point[z[i].first.second] = max(point[z[i].first.second], point[z[i].first.first] + z[i].second);
        }
    }
    if (a == -1000000000000000000)cout << "inf" << endl;
    else cout << point[n - 1] << endl;
}