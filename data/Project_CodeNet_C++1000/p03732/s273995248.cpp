#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,W;
ll w[105],v[105];
ll dp[105][305][105]={};
int main(){
    cin>>N>>W;
    for(ll i=0;i<N;i++){
        cin>>w[i]>>v[i];
    }

    for(ll i=0;i<N;i++){
        for(ll j=0;j<=3*N;j++){
            for(ll k=0;k<N;k++){
                ll ni=i+1;
                ll nj=j+w[i]-w[0];
                dp[ni][nj][k+1]=max(dp[ni][nj][k+1],dp[i][j][k]+v[i]);
                dp[ni][j][k]   =max(dp[ni][j][k],dp[i][j][k]);
            }
        }
    }
    ll ans=0;
    for(ll j=0;j<=3*N;j++){
        for(ll k=1;j+w[0]*k<=W;k++){
            ans=max(ans,dp[N][j][k]);
        }
    }
    cout<<ans<<endl;
    

    return 0;
}