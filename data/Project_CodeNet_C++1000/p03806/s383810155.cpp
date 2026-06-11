#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

static const int N = 40;
static const int INF = 4001;
static const int max_s = N * 10;
int a[N], b[N], c[N], dp[N + 1][max_s + 1][max_s + 1];

int main(){
    int n, ma, mb;
    cin >> n >> ma >> mb;
    rep(i, n)
        cin >> a[i] >> b[i] >> c[i];
    rep(i, n + 1)
        rep(j, max_s + 1)
            rep(k, max_s + 1) dp[i][j][k] = INF;

    dp[0][0][0] = 0;

    rep(i, n)
        rep(sa, max_s + 1)
            rep(sb, max_s + 1){
                if(dp[i][sa][sb] == INF) continue;
                dp[i + 1][sa][sb] = 
                    min(dp[i + 1][sa][sb], dp[i][sa][sb]);
                dp[i + 1][sa + a[i]][sb + b[i]] = 
                    min(dp[i + 1][sa + a[i]][sb + b[i]], dp[i][sa][sb] + c[i]);
            }

    int ans = INF;
    for(int sa = 1; sa <= max_s; sa++)
        for(int sb = 1; sb <= max_s; sb++)
            if(sa * mb == sb * ma) ans = min(ans, dp[n][sa][sb]);
    
    cout << (ans != INF ? ans : -1) << endl;
    return 0;
}