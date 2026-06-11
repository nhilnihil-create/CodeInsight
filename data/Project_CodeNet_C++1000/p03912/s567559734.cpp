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
typedef pair<int, int> P;
const ll INF=2e18;
const ll MOD=1e9+7;
ll N,M;
ll modMap[100010];
ll modPairMap[100010];

int main(){
    cin>>N>>M;    
    map<ll,ll> mp;
    for(ll i=0;i<N;i++){
        ll x;
        cin>>x;
        modMap[x%M]++;
        mp[x]++;
    }
    for(auto p:mp){
        if(p.second>1){
            modPairMap[p.first%M]+=p.second/2*2;
        }
    }
    // for(ll i=0;i<M;i++){
    //     cout<<i<<":"<<modMap[i]<<endl;
    // }
    ll ans=modMap[0]/2;
    if(M%2==0)ans+=modMap[M/2]/2;
    for(ll i=1;i<(M+1)/2;i++){
        ans+=min(modMap[i],modMap[M-i]);
        if(modMap[i]>modMap[M-i]){
            ans+=min(modPairMap[i],modMap[i]-modMap[M-i])/2;
        }else{
            ans+=min(modPairMap[M-i],modMap[M-i]-modMap[i])/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}