#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

template<typename T>
struct BIT {
    int n, p;
    vector<T> d;
    BIT(int n=0) : n(n), d(n+1) {
        p = 1;
        while (p < n) p *= 2;
    }
    void add(int i, T x=1) {
        for (i++; i <= n; i += i&-i) d[i] += x;
    }
    //[0, i)
    T sum(int i) {
        T res = 0;
        for (; i; i -= i&-i) res += d[i];
        return res;
    }
    //[a, b)
    T sum(int l, int r) { return sum(r) - sum(l);} 
    // v0 + v1 + v2 + ... + vx　>= w となる最小のxを求める
    int lower_bound(T w) {
        if (w <= 0) return 0;
        int x = 0;
        for (int i = p; i; i /= 2) {
            if (i+x <= n && d[i+x] < w) {
                w -= d[i+x];
                x += i;
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; ll k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    vll sm(n+1);
    rep(i, n) sm[i+1] = sm[i] + a[i];
    vll b(n+1);
    rep(i, n+1) b[i] = sm[i] - k * i;
    {   // compress
        map<ll, int> mp;
        rep(i, n+1) mp[b[i]] = 0;
        int j = 0;
        for (auto&& p : mp) p.second = j++;
        rep(i, n+1) b[i] = mp[b[i]];
    }
    BIT<int> bit(2e5+1);
    ll ans = 0;
    for (int i = n; i >= 0; --i) {
        ans += bit.sum(b[i], 2e5+1);
        bit.add(b[i]);
    }
    cout << ans << endl;
}