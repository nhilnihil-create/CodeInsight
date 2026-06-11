#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'

int dp[55][55][2550];

signed main() {
    int n,a;
    cin >> n >> a;

    vector<int> x(n);
    rep(i,n) cin >> x[i];

    memset(dp,0,sizeof(dp));
    dp[0][0][0] = 1;

    for(int i = 0; i <= n; i++){
        for(int k = 0; k <= 50; k++){
            for(int s = 0; s <= 2500; s++){
                dp[i + 1][k][s] += dp[i][k][s];
                dp[i + 1][k + 1][s + x[i]] += dp[i][k][s];
            }
        }
    }

    int ans = 0;
    for(int k = 0; k <= 50; k++){
        ans += dp[n][k][k * a];
    }
    cout << ans - 1 << endl;
}