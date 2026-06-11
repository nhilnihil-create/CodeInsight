#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,W;
ll w[101],v[101];
ll dp[101][301][101];
int main(){
    cin>>N>>W;
    for(ll i=0;i<N;i++)cin>>w[i]>>v[i];
    dp[0][0][0]=0;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<=3*N;j++){
            for(ll k=0;k<=i;k++){
                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
                if(j+w[i]-w[0]>3*N)continue;
                dp[i+1][j+w[i]-w[0]][k+1]=max(dp[i+1][j+w[i]-w[0]][k+1],dp[i][j][k]+v[i]);
            }
        }
    }
    ll ans=0;
    for(ll k=0;k<=N;k++){
        for(ll i=0;i<=3*N;i++){
            for(ll j=0;j<=N;j++){
                if(j*w[0]+i>W)continue;
                ans=max(ans,dp[k][i][j]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}