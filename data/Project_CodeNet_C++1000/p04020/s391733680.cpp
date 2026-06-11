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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n) {
        // 2つ以上あるなら、a[i]で作れるだけペアを作る
        if (a[i]>=2) {
            ans += a[i]/2;
            a[i] %= 2;
        }
        // 1余ったら、a[i+1]を見る、ペアが作れるなら貪欲に作る
        if (a[i]==1) {
            if (i<n-1 && a[i+1]>0) {
                ans++;
                a[i+1]--;
            }
        }
        debug(i, ans);
    }
    cout << ans << endl;
}