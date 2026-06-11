#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

int main()
{
    ll N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<ll> a(N), b(N), c(N);
    rep(i, N) cin >> a[i] >> b[i] >> c[i];

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N * 10 + 1, vector<ll>(N * 10 + 1, INF)));

    dp[0][0][0] = 0;
    rep(i, N) {
        rep(j, N * 10 + 1) {
            rep(k, N * 10 + 1) {
                dp[i + 1][j][k] = dp[i][j][k];
                if (j < a[i] || k < b[i]) continue;
                if (dp[i][j - a[i]][k - b[i]] == INF) continue;
                chmin(dp[i + 1][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
            }
        }
    }

    ll ans = INF;
    repd(i, 1, N * 10 + 1) {
        if (i * Ma >= N * 10 + 1 || i * Mb >= N * 10 + 1) break;
        chmin(ans, dp[N][i * Ma][i * Mb]);
    }

    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}