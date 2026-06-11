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
    ll n, k;
    cin >> n >> k;
    vector<ll> z(n);
    vector<vector<ll>> x(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> z[i];
        z[i]--;
        if (z[0] != 0) {
        ans++;
        z[0] = 0;
    }
        x[z[i]].push_back(i);
    }

    vector<ll> kyori(n);
    vector<bool> bol(n,false);
    queue<ll> y;
    y.push(0);
    while (!(y.empty())) {
        ll d = y.front();
        bol[d] = true;
        for (int i = 0; i < x[d].size(); i++) {
            if (bol[x[d][i]] == true)continue;
            y.push(x[d][i]);
            kyori[x[d][i]] = kyori[d] + 1;
        }
        y.pop();
    }
    vector<bool> boles(n,false);
    vector<pair<ll, ll>> qteki(n);
    for (int i = 0; i < n; i++) {
        qteki[i].first = kyori[i];
        qteki[i].second = i;
    }
    sort(qteki.begin(), qteki.end());
    reverse(qteki.begin(), qteki.end());
    for (int i = 0; i < n; i++) {
        if(boles[qteki[i].second] == true)continue;
        if (qteki[i].first <= k)continue;
        boles[qteki[i].second] = true;
        ll po = qteki[i].second;
        ll fr = 0;
        for (int j = 0; j < k-1; j++) {
            po = z[po];
            if (boles[po] == true) {
                fr = 1;
                break;
            }
            boles[po] = true;
            if (po == 0)break;
        }
        if (z[po] != 0&&fr==0) {
            ans++;
            z[po] = 0;
        }
    }
    cout << ans << endl;
}