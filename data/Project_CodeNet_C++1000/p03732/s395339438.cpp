#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    // 重さでグループ分け
    vector<vector<ll>> a(4, vector<ll>());
    rep(i, N) a[w[i] - w[0]].push_back(v[i]);
    rep(i, 4) sort(a[i].rbegin(), a[i].rend());

    // 累積和
    vector<vector<ll>> s(4, vector<ll>());
    rep(i, 4) {
        s[i].resize(a[i].size() + 1);
        rep(j, a[i].size()) s[i][j + 1] = s[i][j] + a[i][j];
    }

    ll ans = 0;
    rep(i, s[0].size()) {
        rep(j, s[1].size()) {
            rep(k, s[2].size()) {
                rep(l, s[3].size()) {
                    ll weight = w[0] * i + (w[0] + 1) * j + (w[0] + 2) * k + (w[0] + 3) * l;
                    if (weight <= W) chmax(ans, s[0][i] + s[1][j] + s[2][k] + s[3][l]);
                }
            }
        }
    }

    cout << ans << endl;
}