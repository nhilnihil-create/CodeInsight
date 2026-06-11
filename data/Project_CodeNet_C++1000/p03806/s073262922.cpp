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

int a[45], b[45], c[45];
ll dp[45][450][450];


int main(){
    int n, ma, mb;
    cin >> n >> ma >> mb;
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    rep(k, 45) rep(i, 450) rep(j, 450){
        dp[k][i][j] = LINF;
    }
    dp[0][0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int p = 0; p <= 400; p++){
            for(int q = 0; q <= 400; q++){
                if (p >= a[i-1] && q >= b[i-1]) dp[i][p][q] = min(dp[i-1][p][q], dp[i-1][p - a[i-1]][q - b[i-1]] + c[i-1]);
                else dp[i][p][q] = dp[i-1][p][q];
            }
        }
    }

    ll ans = LINF;
    for (int p = 1; p < 1000; p++){
        int x = ma * p;
        int y = mb * p;
        if (x > 400 || y > 400) continue;
        ans = min(ans, dp[n][x][y]);
    }

    if (ans == LINF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
