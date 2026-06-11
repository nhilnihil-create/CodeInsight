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

ll N,A;
ll x[100];
ll dp[51][51][2501];
int main(){
    cin>>N>>A;
    for(ll i=0;i<N;i++){
        cin>>x[i];
    }
    dp[0][0][0]=1;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<=N;j++){
            for(ll k=0;k<=N*50;k++){
                dp[i+1][j][k]+=dp[i][j][k];
                if(k+x[i]>N*50 || j+1>N)continue;
                dp[i+1][j+1][k+x[i]]+=dp[i][j][k];
            }
        }
    }
    ll ans=0;
    for(ll j=1;j<=N;j++){
        for(ll k=0;k<=N*50;k++){
            if(k%j==0 && k/j==A)ans+=dp[N][j][k];
        }
    }
    cout<<ans<<endl;
    return 0;
}