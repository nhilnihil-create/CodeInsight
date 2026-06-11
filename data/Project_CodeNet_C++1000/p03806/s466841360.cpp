#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,Ma,Mb;
ll dp[50][410][410];
ll a[50],b[50],c[50];
int main(){
    cin>>N>>Ma>>Mb;
    for(ll i=0;i<=N;i++){
        for(ll j=0;j<=400;j++){
            for(ll k=0;k<=400;k++){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    for(ll i=0;i<N;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(ll i=0;i<N;i++){
        for(ll j=0;j<=400;j++){
            for(ll k=0;k<=400;k++){
                dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
                dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
            }
        }
    }
    ll ans=INF;
    for(ll i=0;i<=400;i++){
        for(ll j=0;j<=400;j++){
            if(i!=0 && j!=0 && i*Mb==j*Ma){
                ans=min(ans,dp[N][i][j]);
            }
        }
    }
    cout<<(ans==INF?-1:ans)<<endl;
}