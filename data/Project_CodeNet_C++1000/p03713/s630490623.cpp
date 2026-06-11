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

ll H,W;
int main(){
    cin>>H>>W;
    ll ans=INF;
    for(ll i=1;i<H;i++){
        ll a=W*i;
        ll b,c;
        if( (H-i)%2==1 && W%2==1){
            b=(H-i)*(W/2);
            c=(H-i)*((W+1)/2);
            ans=min(ans,max({a,b,c})-min({a,b,c}));
            b=W*((H-i)/2);
            c=W*((H-i+1)/2);
            ans=min(ans,max({a,b,c})-min({a,b,c}));
        }else{
            b=(H-i)*W/2;
            ans=min(ans,abs(a-b));
        }
    }
    for(ll i=1;i<W;i++){
        ll a=H*i;
        ll b,c;
        if( (W-i)%2==1 && H%2==1){
            b=(W-i)*(H/2);
            c=(W-i)*((H+1)/2);
            ans=min(ans,max({a,b,c})-min({a,b,c}));
            
            b=H*((W-i)/2);
            c=H*((W-i+1)/2);
            ans=min(ans,max({a,b,c})-min({a,b,c}));
        }else{
            b=(W-i)*H/2;
            ans=min(ans,abs(a-b));
        }
    }
    cout<<ans<<endl;
    return 0;
}