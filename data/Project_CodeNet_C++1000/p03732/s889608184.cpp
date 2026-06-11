#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[101][101][500];

template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    ll base = w[0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k <= 300; k++) {
                ll gap = w[i] - base;
                chmax(dp[i + 1][j + 1][k + gap], dp[i][j][k] + v[i]);
                chmax(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j * base <= W; j++) {
        for (int k = 0; k <= 300; k++) {
            if (W < j * base + k) break;
            chmax(ans, dp[N][j][k]);
        }
    }
    cout << ans << endl;
}