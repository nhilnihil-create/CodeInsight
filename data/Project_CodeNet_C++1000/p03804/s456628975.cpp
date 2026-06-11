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
const int INF = 1e9;
const int MOD = 1e9+7;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    vector<string> b(m);
    rep(i, m) cin >> b[i];

    bool found = false;
    rep(i, n-m+1) rep(j, n-m+1) {
        bool ok = true;
        rep(k, m) rep(l, m) {
            debug(i, j, k, l);
            if (a[i+k][j+l]!=b[k][l]) ok = false;
        }
        if (ok) found = true;
    }
    if (found) puts("Yes");
    else puts("No");
}