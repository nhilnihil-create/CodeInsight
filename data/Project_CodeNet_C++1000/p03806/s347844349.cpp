#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;
map<int,int>mp;
const int N=2e5+100;
int dp[50][500][500];///前n个a有i，b有j的最小花费
int a[50],b[50],c[50];
int inf=0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m1,m2;
    cin>>n>>m1>>m2;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    memset(dp,0x3f,sizeof dp);
    dp[1][0][0]=0;
    for(int i=1;i<=n;i++){
       for(int j=0;j<=400;j++){
        for(int k=0;k<=400;k++){
            if(dp[i][j][k]==inf) continue;
           dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
           dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
       }
     }
    }
    int ans=inf;
    for(int i=1;i<=400;i++){
        if(i*m1<=400&&i*m2<=400){
            ans=min(ans,dp[n+1][i*m1][i*m2]);
        }
    }
    if(ans!=inf)
    cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
