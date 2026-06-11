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

int n, m, a[1005], b[1005], c[1005];
int g[105][105];

int main() {
    int n, m;
    cin >> n >> m;

    rep(i, n) rep(j, n) g[i][j] = INF;
    rep(i, n) g[i][i] = 0;
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        g[a[i]][b[i]] = g[b[i]][a[i]] = c[i];
    }

    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                chmin(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i, m) {
        if (c[i] > g[a[i]][b[i]]) ans++;
    }
    cout << ans << endl;
}
