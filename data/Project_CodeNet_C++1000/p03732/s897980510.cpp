#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;
ll n,W,w[100],v[100],dp[110][310][110]={};
int main(void){
    ll ans=0;
    cin>>n>>W;
    for(int i=0;i<n;i++) cin>>w[i]>>v[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<300;j++){
            for(int k=0;k<n;k++){
                dp[i+1][j][k+1]=dp[i][j][k+1];
                if(w[i]-w[0]<=j) dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j-(w[i]-w[0])][k]+v[i]);
                if((k+1)*w[0]+j<=W) ans=max(ans,dp[i+1][j][k+1]);
            }
        }
    }
    cout<<ans<<endl;
}