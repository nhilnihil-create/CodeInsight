#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    const ll inf = 1e12;
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n, 0));
    rep(i, n) rep(ii, n) cin >> a[i][ii];
    vector<vector<ll>> d(n, vector<ll>(n, 0));
    ll ans = 0;
    rep(i, n) rep(ii, n) d[i][ii] = a[i][ii];
    rep(i, n) {
        rep(ii, n) {
            rep(iii, n) {
                d[ii][iii] = min(d[ii][iii], d[ii][i] + d[i][iii]);
            }
        }
    }
    rep(i, n) {
        rep(ii, n) {
            if (d[i][ii] != a[i][ii]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    rep(i, n) {
        rep(ii, n) {
            rep(iii, n) {
                if ((i == ii) || (i == iii)) continue;
                if (d[ii][iii] == (d[ii][i] + d[i][iii])) {
                    // printf("%d->%d = %d->%d->%d\n", ii, iii, ii, i, iii);
                    d[ii][iii] = inf;
                    d[iii][ii] = inf;
                }
            }
        }
    }
    rep(i, n) {
        rep(ii, n) {
            if (d[i][ii] != inf) ans = ans + d[i][ii];
            // printf("%d%s", d[i][ii], (ii == (n - 1)) ? "\n" : " ");
        }
    }
    cout << (ans / 2) << endl;
    return 0;
}
