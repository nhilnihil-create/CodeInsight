#include <iostream>
using namespace std;

const int INF = 1000000;

int dp[42][402][402];

int main()
{
    int n, ma, mb;
    cin >> n >> ma >> mb;
    int a[42], b[42], c[42];
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 400; j++){
            for(int k = 0; k <= 400; k++) dp[i][j][k] = INF;
        }
    }
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 400; j++){
            for(int k = 0; k <= 400; k++){
                dp[i][j][k] = dp[i - 1][j][k];
            }
        }
        for(int j = a[i - 1]; j <= 400; j++){
            for(int k = b[i - 1]; k <= 400; k++){
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - a[i - 1]][k - b[i - 1]] + c[i - 1]);
            }
        }
    }
    int ans = INF;
    for(int i = 1; i * ma <= 400 && i * mb <= 400; i++){
        ans = min(ans, dp[n][i * ma][i * mb]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
