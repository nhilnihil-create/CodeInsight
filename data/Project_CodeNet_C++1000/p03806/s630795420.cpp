#include <iostream>
#include <algorithm>
using namespace std;
int n,A,B;
int a[40],b[40],c[40];
int dp[50][500][500];
int main(){
    cin>>n>>A>>B;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
    for(int i=0;i<=n;i++)for(int j=0;j<500;j++)for(int k=0;k<500;k++)dp[i][j][k]=100000;
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int ca=0;ca<=400;ca++){
            for(int cb=0;cb<=400;cb++){
                dp[i+1][ca][cb]=min(dp[i][ca][cb],dp[i+1][ca][cb]);
                dp[i+1][ca+a[i]][cb+b[i]]=min(dp[i+1][ca+a[i]][cb+b[i]],dp[i][ca][cb]+c[i]);
            }
        }
    }
    int ans=4000000;
    for(int i=1;i*max(A,B)<500;i++){
        ans=min(ans,dp[n][i*A][i*B]);
    }
    if(ans==100000) cout<<-1;
    else cout<<ans;
    return 0;
}
