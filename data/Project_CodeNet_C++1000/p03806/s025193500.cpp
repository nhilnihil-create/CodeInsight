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

ll dp[50][500][500]; // i番目まで見て、maをj、mbをk取ることができる最小予算
int a[50], b[50], c[50];

int main(){
    int n, ma, mb;
    cin >> n >> ma >> mb;
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    rep(i, 50) rep(j, 500) rep(k, 500) dp[i][j][k] = LINF;
    dp[0][0][0] = 0;

    for(int i = 1; i <= n; i++){
        rep(j, 450) rep(k, 450){
            if (j >= a[i-1] && k >= b[i-1]) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-a[i-1]][k-b[i-1]]+c[i-1]);
            dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
        }
    }

    ll ans = LINF;

    for(int i = 1; i < 500; i++){
        if (i * ma >= 500 || i * mb >= 500) continue;
        ans = min(ans, dp[n][i*ma][i*mb]);
    }

    if (ans == LINF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
