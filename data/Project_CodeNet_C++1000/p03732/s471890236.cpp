#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,W;
    cin>>n>>W;
    long long w[n],v[n];
    for(int i=0;i<n;i++)cin>>w[i]>>v[i];
    long long dp[n+1][n+1][n*3+1];//i個見てj個選んでkの重さのときの最大価値
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n*3;k++)dp[i][j][k]=-1000000000;
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n*3;k++){
                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
                if(j<n && k+w[i]-w[0]<=n*3)dp[i+1][j+1][k+w[i]-w[0]]=max(dp[i+1][j+1][k+w[i]-w[0]],dp[i][j][k]+v[i]);
            }
        }
    }
    long long m=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n*3;j++){
            if(W-w[0]*i>=j)m=max(m,dp[n][i][j]);
        }
    }
    cout<<m<<endl;
    return 0;
}