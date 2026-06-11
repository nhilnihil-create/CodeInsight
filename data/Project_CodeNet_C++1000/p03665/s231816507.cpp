#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,p;
    cin>>n>>p;
    int a[n];
    long long dp[n+1][2]={};
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<2;j++){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][(j+a[i])%2]+=dp[i][j];
        }
    }
    cout<<dp[n][p]<<endl;
    return 0;
}