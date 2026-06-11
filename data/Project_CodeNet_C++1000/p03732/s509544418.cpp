#include<bits/stdc++.h>
using namespace std;
int w1[110],v[110];
const int inf=0x3f3f3f3f;
#define ll long long 
int dp[110][110][330];
ll ans;
int main(){
    int n,w,i,j,k;
    scanf("%d%d",&n,&w);
    for(i=1;i<=n;i++)
         cin>>w1[i]>>v[i];
    
    for(i=1;i<=n;i++)
    
        for(j=0;j<=i;j++)
          for(k=0;k<=3*j;k++)
          
        {
           dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
           dp[i+1][j+1][k+w1[i]-w1[1]]=max(dp[i+1][j+1][k+w1[i]-w1[1]],dp[i][j][k]+v[i]);
        }
    int ans=0 ;
    for (int i=0;i<=n;i++)
    for (int j=0;j<=3*i;j++){
        ll W= (ll) w1[1]*i+j;
        if (W<=w) ans=max(ans,dp[n+1][i][j]) ;
    }
    printf("%d",ans) ;
    return 0 ;

}