#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    int n, ma, mb;
    cin >> n >> ma >> mb;

    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n*10 + 1, vector<int>(n*10 + 1, INF)));// dp[items][a][b]
    dp[0][0][0] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n*10; j++){
            for(int k=0; k<n*10; k++){
                if(dp[i][j][k] == INF) continue;

                dp[i+1][j][k]           = min(dp[i+1][j][k],           dp[i][j][k]       );
                dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
            }
        }
    }

    int ans = INF;
    for(int j=1; j<=n*10; j++){
        for(int k=1; k<=n*10; k++){
            if(j * mb == k * ma) ans = min(ans, dp[n][j][k]);
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}