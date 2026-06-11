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
ll a[200010];
unordered_map<ll,ll> pos;
int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    set<ll> posSet;
    ll ans=0;
    for(ll i=1;i<=N;i++){
        auto upperIt=posSet.upper_bound(pos[i]);
        ll l,r;
        if(upperIt==posSet.end()){
            r=N-1;
        }else{
            r=*upperIt-1;
        }
        if(upperIt==posSet.begin()){
            l=0;
        }else{
            auto downerIt=upperIt;
            downerIt--;
            l=*downerIt+1;
        }
        ans+=i*(pos[i]-l+1)*(r-pos[i]+1);
        posSet.insert(pos[i]);
    }
    cout<<ans<<endl;
    return 0;
}