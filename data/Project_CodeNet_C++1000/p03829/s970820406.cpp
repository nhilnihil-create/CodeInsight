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

ll N,A,B;
ll x[100010];
int main(){
    cin>>N>>A>>B;
    ll ans=0;
    for(ll i=0;i<N;i++){
        cin>>x[i];
        if(i>0){
            ans+=min(B,A*(x[i]-x[i-1]));
        }
    }
    cout<<ans<<endl;
    return 0;
}