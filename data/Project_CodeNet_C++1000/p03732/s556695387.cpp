#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, W;
    cin >> n >> W;

    vector<ll> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    ll w0 = w[0];
    rep(i, n) w[i] -= w0;

    // dp[i][j][k]: i個までみたときのj個選んで重さが k (j+j*w0) である最大のvalue
    // 選んだ個数も保存しないといけない
    vector<vector<vector<ll> > > dp(
        n+1, 
        vector<vector<ll>>(n+1, vector<ll>(400)));

    repi(i, n+1) {
        rep(k, 400) {
            // i-1個目を選ぶ場合
            repi(j, n+1) {
                if (k-w[i-1] >= 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-w[i-1]] + v[i-1]);
            }
            // i-1個目はスキップ
            repi(j, n+1) {
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
            }
        }
    }

    ll res = 0;
    rep(j, n + 1) {
        rep(k, 400) {
            ll actualW = j * w0 + k;
            if (actualW <= W) {
                res = max(res, dp[n][j][k]);
            }
        }
    }

    put(res);
}
signed main(){ Main();return 0;}