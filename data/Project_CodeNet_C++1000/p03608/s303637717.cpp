#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MAX / 2 - 1;
    ll N, M, R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }
    sort(all(r));
    vector<vector<ll>> dist(N, vector<ll>(N, inf));
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    rep(i, N) rep(j, N) rep(k, N) chmin(dist[j][k], dist[j][i] + dist[i][k]);
    ll ans = inf;
    do {
        ll tmp = 0;
        rep(i, R - 1) {
            tmp += dist[r[i]][r[i + 1]];
        }
        chmin(ans, tmp);
    }
    while(next_permutation(all(r)));
    cout << ans << endl;
    return 0;
}
