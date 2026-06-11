#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    map<ll, ll> mp;
    rep(i, n) mp[a[i]]++;
    vi v;
    v.pb(0);
    for (int i = 1; i < n; ++i) if (a[v.back()] < a[i]) v.pb(i);
    vll ans(n, 0);
    for (int i = sz(v) - 2; i >= 0; --i) {
        while ((*mp.rbegin()).fi > a[v[i]]) {
            auto p = *mp.rbegin();
            mp.erase(p.fi);
            ans[v[i+1]] += (p.fi - a[v[i]]) * 1LL * p.se;
            mp[a[v[i]]] += p.se;
        }
    }
    for (auto p : mp) {
        ans[0] += p.fi * p.se;
    }

    rep(i, n) cout << ans[i] << endl;

}