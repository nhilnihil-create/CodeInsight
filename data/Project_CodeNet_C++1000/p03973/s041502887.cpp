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

ll N;
int main(){
    cin>>N;
    ll now=1;
    ll ans=0;
    for(ll i=0;i<N;i++){
        ll a;
        cin>>a;
        if(now==a){
            now++;
        }else{
            ans+=(a-1)/now;
            if(now==1)now=2;
        }
    }
    cout<<ans<<endl;
    return 0;
}