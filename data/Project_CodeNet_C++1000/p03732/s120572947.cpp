#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int dp[105][105][305];

int w[105],v[105];
int32_t main() {

    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,m;

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    int w1 = w[1];
    for(int i=1;i<=n;i++){
        w[i]-=w1;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n*3;k++){
                if(w1+w[i]<=j*w1+k&&k>=w[i]&&j){
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-1][k-w[i]]+v[i]);
                }
                else dp[i][j][k] = dp[i-1][j][k];
            }
        }
    }
    int ans = 0;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=3*n;j++){
            if(i*w1+j<=m){
                ans = max(ans,dp[n][i][j]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}