#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    ll N, W;
    cin >> N >> W;

    vec<ll> w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    vec<vec<vec<ll>>> dp(N+1, vec<vec<ll>>(N+1, vec<ll>(301, 0)));
    rep(i, N) {
        ll wp           = w[i] - w[0];
        dp[i + 1][1][wp] = max(dp[i + 1][1][wp], v[i]);
        rep(j, N) rep(k, 2*N+2) {
            dp[i + 1][j][k] = max(dp[i + 1][j][k],dp[i][j][k]);
            if (dp[i][j][k] != 0) {
                dp[i + 1][j + 1][k + wp] =
                    max(dp[i + 1][j + 1][k + wp], dp[i][j][k] + v[i]);
            }
        }
    }

    ll ans = 0;
    rep(j,N+1)rep(k,250){
        if(j*w[0]+k<=W) ans = max(ans,dp[N][j][k]);
    }
    cout << ans << '\n';
}
