#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


ll w[110], v[110];
ll dp[110][110][310];

int main(){
    int n;
    ll W;
    cin >> n >> W;
    rep(i, n) cin >> w[i] >> v[i];

    ll head = w[0];

    rep(i, n) w[i] -= head;

    rep(i, n) rep(j, n) rep(k, 310){
        if (w[i] <= k) dp[i + 1][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k - w[i]] + v[i]);
        else dp[i + 1][j + 1][k] = dp[i][j + 1][k];
    }

    ll ans = 0;

    rep(j, n+1) rep(k, 310) {
        if (k + head * j <= W) ans = max(ans, dp[n][j][k]);
    }

    cout << ans << endl;
    return 0;
}
