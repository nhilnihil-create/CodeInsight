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
#include <fstream>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iomanip>
#include <float.h>
#include <math.h>
#include <cassert>
#pragma warning (disable: 4996)
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

ll ll_gcd(ll a, ll b) {
    if (a < b) return ll_gcd(b, a);
    ll r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

struct UnionFind {
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
    if (n < 0)return 0;
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

ll merge_cnt(vector<ll>& a) {
    int n = a.size();
    if (n <= 1) { return 0; }

    ll cnt = 0;
    vector<ll> b(a.begin(), a.begin() + n / 2);
    vector<ll> c(a.begin() + n / 2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    int ai = 0, bi = 0, ci = 0;
    while (ai < n) {
        if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci])) {
            a[ai++] = b[bi++];
        }
        else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    vector<int> z(26);
    vector<int> x(n);
    vector<int> d(n+2);
    vector<vector<int>> b(n + 2);
    ll k = 0;
    for (int i = 0; i < n; i++) {
        while (true) {
            ll m = 0;
            for (int i = 0; i < 26; i++) {
                if (z[i] == 0)m = 1;
            }
            if (m == 0)break;
            if (k == n + 1)break;
            if (k == n) {
                k++;
                break;
            }
            z[s[k] - 'a']++;
            k++;
        }
        x[i] = k;
        b[x[i]].push_back(i);
        z[s[i] - 'a']--;
    }
    b[n + 1].push_back(n);
    for (int i = n + 1; i > -1; i--) {
        for (int j = 0; j < b[i].size(); j++) {
            d[b[i][j]] = d[i]+1;
        }
    }
    ll h = d[0];
    string ans = "";
    ll c = 0;
    for (int i = 0; i < h; i++) {
        vector<bool>v(26,true);
        for (int j = c; j < n; j++) {
            if (d[j+1] != h - i)break;
            v[s[j] - 'a'] = false;
            c++;
        }
        for (int i = 0; i < 26; i++) {
            if (v[i]) {
                ans.push_back(char('a' + i));
                break;
            }
        }
        for (int j = c; j < n; j++){
            c++;
            if (s[j] == ans[ans.size()-1])break;
        }
    }
    cout << ans << endl;
}