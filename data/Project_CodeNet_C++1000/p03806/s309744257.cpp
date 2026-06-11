#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=45,NN=405, inf=1e17;
ll a[N],b[N],c[N],dp[N][NN+10][NN+10];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,ma,mb;cin>>n>>ma>>mb;
    for(ll i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
    for(ll i=0;i<=n;i++)for(ll ca=0;ca<NN+10;ca++)for(ll cb=0;cb<NN+10;cb++)dp[i][ca][cb]=inf;
    dp[0][0][0]=0;
    for(ll i=0;i<n;i++){
        for(ll ca=0;ca<NN;ca++){
            for(ll cb=0;cb<NN;cb++){
                if(dp[i][ca][cb]==inf)continue;
                dp[i+1][ca][cb]=min(dp[i+1][ca][cb],dp[i][ca][cb]);
                dp[i+1][ca+a[i]][cb+b[i]]=min(dp[i+1][ca+a[i]][cb+b[i]] , dp[i][ca][cb] + c[i]);
            }
        }
    }

    ll ans=inf;
    for(ll ca=1;ca<NN;ca++)for(ll cb=1;cb<NN;cb++)if(ca*mb==cb*ma)ans=min(ans,dp[n][ca][cb]);
    if(ans==inf)ans=-1;
    cout<<ans;
}
