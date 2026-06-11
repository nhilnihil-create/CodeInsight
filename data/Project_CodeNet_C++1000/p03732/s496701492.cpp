#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

const int INF = 1e9 + 5;

// input
int N, W;
vector<ll> w, v;

vector<map<ll, ll>> m;


void input() {
    cin >> N >> W;
    w = v = vector<ll>(N);
    rep(i, N) cin >> w[i] >> v[i];
}


int main() {
    input();
    m = vector<map<ll, ll>>(N + 1);
    rep(k, N + 1) rep(i, k + 1) rep(j, 3 * i + 1) m[k][i * w[0] + j] = -INF;
    m[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        rep(j, i + 1) rep(k, 3 * j + 1) {
            ll x = j * w[0] + k;
            if (W < x) continue;
            if (m[i - 1].count(x)) m[i][x] = m[i - 1][x];
            ll y = x - w[i - 1];
            if (m[i - 1].count(y)) m[i][x] = max(m[i][x], m[i - 1][y] + v[i - 1]);
        }
    }
    ll ans = 0;
    rep(i, N + 1) rep(j, 3 * i + 1) ans = max(ans, m[N][i * w[0] + j]);
    cout << ans << endl;
}
