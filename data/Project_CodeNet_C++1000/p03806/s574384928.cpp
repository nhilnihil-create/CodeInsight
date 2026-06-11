#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ma, mb;
    cin >> n >> ma >> mb;
    int dp[10 * n + 3][10 * n + 3];
    for(int i = 0; i <= 10 * n; i++){
        for(int j = 0; j <= 10 * n; j++){
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = 10 * n - a; j >= 0; j--){
            for(int k = 10 * n - b; k >= 0; k--){
                dp[j + a][k + b] = min(dp[j + a][k + b], dp[j][k] + c);
            }
        }
    }
    int k = 1, ans = 1e9;
    while(1 == 1){
        if(ma * k >= 10 * n || mb * k >= 10 * n){
            break;
        }
        ans = min(ans, dp[ma * k][mb * k]);
        k++;
    }
    if(ans == 1e9){
        cout << "-1";
    }
    else{
        cout << ans;
    }
    return 0;
}