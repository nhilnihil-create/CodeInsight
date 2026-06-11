#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,A,B;
    cin>>n>>A>>B;
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(401,vector<int>(401,10000)));
    dp[0][0][0]=0;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
        for(int j=0;j<=390;j++){
            for(int k=0;k<=390;k++){
                dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
                dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
            }
        }
    }
    int m=10000;
    for(int i=1;max(A,B)*i<=400;i++)m=min(m,dp[n][A*i][B*i]);
    if(m<10000)cout<<m<<endl;
    else cout<<"-1"<<endl;
    return 0;
}