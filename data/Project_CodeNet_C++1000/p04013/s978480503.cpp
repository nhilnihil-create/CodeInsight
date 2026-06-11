#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ll n,a,x[50];
    cin>>n>>a;
    for(int i=0;i<n;i++) cin>>x[i];
    ll dp[51][51][2501]={};
    for(int i=0;i<=50;i++) dp[i][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<=n*a;k++){
                if(k>=x[i]) dp[i+1][j][k]=dp[i][j][k]+dp[i][j-1][k-x[i]];
                else dp[i+1][j][k]=dp[i][j][k];
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[n][i][i*a];
    }
    cout<<ans<<endl;
}
