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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> a(n), s(n+1);
    rep(i, n) cin >> a[i];
    sort(all(a));
    rep(i, n) s[i+1] += s[i]+a[i];
    debug(a);
    debug(s);
    int ans = 1;
    for(int i=n-1; i>0; i--) {
        if (s[i]*2>=a[i]) ans++;
        else break;
    }
    cout << ans << endl;
}