#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)

const int INF = 1 << 29;

int main(void){
    int n,ma,mb;
    cin >> n >> ma >> mb;
    int a[n],b[n],c[n];
    rep(i,n)cin >> a[i] >> b[i] >> c[i];
    
    int alina = INF;
    
    int dp[n+1][n*11][n*11];
    rep(i,n+1){
        rep(j,n*11){
            rep(l,n*11)dp[i][j][l] = INF;
        }
    }
    dp[0][0][0] = 0;
    
    rep(i,n){
        for(int j = 0;j <= 10*n;j++){
            for(int l = 0;l <= 10*n;l++){
                dp[i+1][j][l] = dp[i][j][l];
                if(j >= a[i] && l >= b[i]){
                    dp[i+1][j][l] = min(dp[i+1][j][l],dp[i][j-a[i]][l-b[i]]+c[i]);
                }
                if(j / ma == l / mb && j % ma == 0 && l % mb == 0 && i > 0 && j > 0){
                    alina = min(alina,dp[i+1][j][l]);
                }
            }
        }
    }
    
    if(alina == INF)alina = -1;
    cout << alina << endl;
}