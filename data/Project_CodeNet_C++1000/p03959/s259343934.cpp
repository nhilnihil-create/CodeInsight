#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int n; cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> mint(n);
    vector<int> maxt(n);
    int cur = 0;
    rep(i, n) {
        if (t[i]>cur) {
            mint[i] = t[i];
            maxt[i] = t[i];
            cur = t[i];
        } else {
            mint[i] = 1;
            maxt[i] = maxt[i-1];
        }
    }
    debug(mint, maxt);
    reverse(all(a));
    vector<int> mina(n);
    vector<int> maxa(n);
    cur = 0;
    rep(i, n) {
        if (a[i]>cur) {
            mina[i] = a[i];
            maxa[i] = a[i];
            cur = a[i];
        } else {
            mina[i] = 1;
            maxa[i] = maxa[i-1];
        }
    }
    reverse(all(mina));
    reverse(all(maxa));
    debug(mina, maxa);
    ll ans = 1;
    rep(i, n) {
        int lb = max(mint[i], mina[i]);
        int ub = min(maxt[i], maxa[i]);
        if (ub<lb) {
            cout << 0 << endl;
            return 0;
        }
        ans *= ub-lb+1ll;
        ans %= MOD;
        debug(lb, ub, ans);
    }
    cout << ans << endl;
}