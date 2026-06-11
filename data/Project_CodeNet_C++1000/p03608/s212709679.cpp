#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }

    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    sort(all(r));

    ll ans = INF;

    do {
        ll tmp = 0;
        rep(i, R - 1) { tmp += dist[r[i]][r[i + 1]]; }

        ans = min(ans, tmp);

    } while (next_permutation(all(r)));

    cout << ans << endl;
}