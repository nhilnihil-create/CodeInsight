#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int N, M, R;
int MAX = 210;
vector<vector<ll>> dist(MAX, vector<ll>(MAX));

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> R;
    vector<ll> r(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }

    dist.assign(N + 5, vector<ll>(N + 5, INF));
    rep(i, N + 5) { dist[i][i] = 0; }

    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    // ワーシャルフロイド
    rep(k, N) {
        rep(i, N) {
            rep(j, N) { dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); }
        }
    }

    sort(all(r));

    ll ans = INF;
    do {
        ll temp = 0;
        for (int i = 1; i < R; i++) {
            temp += dist[r[i]][r[i - 1]];
        }

        ans = min(ans, temp);
    } while (next_permutation(all(r)));

    cout << ans << endl;
}