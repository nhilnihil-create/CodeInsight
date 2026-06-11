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

void dfs(vector<vector<ll>> &p, vector<ll> &oyaa,ll &ans,ll now,ll oyan, vector<ll> &ansoyaa,ll nnow,ll node,ll &nownode) {
    if (nownode <= node)return;
    if (oyaa[now] != -1 && nownode > node) {
        oyaa[now] = oyan;
        ans = now;
        nownode = node;
        for (int i = 0; i < oyaa.size(); i++) {
            ansoyaa[i] = oyaa[i];
        }
        oyaa[now] = -1;
        return;
    }
    oyaa[now] = oyan;
    for (int i = 0; i < p[now].size(); i++) {
        dfs(p, oyaa, ans, p[now][i], now,ansoyaa,nnow,node+1,nownode);
    }
    oyaa[now] = -1;
    return;
}

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    a = a - b;
    vector<ll> z(n);
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    ll ok = 1000000000;
    ll ng = 0;
    while(abs(ok-ng)>1){
        ll mid = (ok + ng) / 2;
        vector<ll> zz(n);
        for (int i = 0; i < n; i++) {
            zz[i]= z[i];
            zz[i] -= b * mid;
            ll za = 0;
            zz[i] = max(zz[i], za);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (zz[i] + a - 1) / a;
        }
        if (ans <= mid)ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}