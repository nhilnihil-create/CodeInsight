#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    cin>>n>>a;
    int x[n];
    vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(n+1,vector<long long>(2501,0)));
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        cin>>x[i];
        for(int j=0;j<=n;j++){
            for(int k=0;k<=2450;k++){
                dp[i+1][j][k]+=dp[i][j][k];
                if(j<n)dp[i+1][j+1][k+x[i]]+=dp[i][j][k];
            }
        }
    }
    long long ans=0;
    for(int i=0;i<=n;i++)for(int j=0;j<=2500;j++)if(i*a==j)ans+=dp[n][i][j];
    cout<<ans-1<<endl;
    return 0;
}