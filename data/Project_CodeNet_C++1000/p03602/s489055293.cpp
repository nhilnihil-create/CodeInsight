#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MAX / 2 - 1;
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n)), g(n, vector<ll>(n));
    rep(i, n) {
        rep(j, n) {
            cin >> a[i][j];
            g[i][j] = a[i][j];
        }
    }
    rep(i, n) rep(j, n) rep(k, n) g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
    rep(i, n) {
        rep(j, n) {
            if (a[i][j] != g[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                if ((i == j) || (i == k) || (j == k)) continue;
                if (g[j][k] != (g[j][i] + g[i][k])) continue;
                g[j][k] = inf;
                g[k][j] = inf;
            }
        }
    }
    ll ans = 0;
    rep(i, n) {
        rep(j, n) {
            if (g[i][j] == inf) continue;
            ans += g[i][j];
        }
    }
    cout << (ans / 2) << endl;
    return 0;
}
