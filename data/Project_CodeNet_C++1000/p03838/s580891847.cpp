//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll x,y;
    cin>>x>>y;
    ll ans=10000000000000000;
    if(x<=y){
        ans=min(ans,y-x);
    }
    if(-x<=y){
        ans=min(ans,y+x+1);
    }
    if(x<=-y){
        ans=min(ans,-y-x+1);
    }
    if(-x<=-y){
        ans=min(ans,-y+x+2);
    }
    cout<<ans<<endl;
    
}
