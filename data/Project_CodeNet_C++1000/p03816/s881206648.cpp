#include<iostream>
#include<iomanip>
#include<math.h>
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

ll N;
map<ll,ll> mp;
int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        ll a;
        cin>>a;
        mp[a]++;
    }
    ll cnt=0;
    for(auto p:mp){
        if(p.second>1){
            cnt+=p.second-1;
        }
    }
    cout<<N-(cnt+1)/2*2<<endl;
    return 0;
}