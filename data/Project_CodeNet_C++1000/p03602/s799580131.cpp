#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;
ll g[305][305], h[305][305];

int main() {
    cin >> n;
    rep(i, n) rep(j, n) cin >> g[i][j];
    rep(i, n) rep(j, n) h[i][j] = g[i][j];

    rep(k, n) rep(i, n) rep(j, n) {
        if (chmin(g[i][j], g[i][k] + g[k][j])) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll ans = 0;
    // g[i][j] を残すか？
    rep(i, n) rep(j, n) {
        if (i >= j) continue;
        bool ok = true;
        rep(k, n) {
            if (i == k || j == k) continue;
            if (g[i][j] >= g[i][k] + g[k][j]) ok = false;
        }
        if (ok) ans += g[i][j];
    }
    cout << ans << endl;
}
