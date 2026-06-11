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

ll H,W;
int main(){
    cin>>H>>W;
    ll ans=min((H%3!=0)*W,(W%3!=0)*H);
    for(ll i=1;i<H;i++){
        ll mi=min({(W+1)/2*(H-i),W/2*(H-i),i*W});
        ll ma=max({(W+1)/2*(H-i),W/2*(H-i),i*W});
        ans=min(ma-mi,ans);
    }
    for(ll i=1;i<W;i++){
        ll mi=min({(H+1)/2*(W-i),H/2*(W-i),i*H});
        ll ma=max({(H+1)/2*(W-i),H/2*(W-i),i*H});
        ans=min(ma-mi,ans);
    }
    cout<<ans;
    return 0;
}