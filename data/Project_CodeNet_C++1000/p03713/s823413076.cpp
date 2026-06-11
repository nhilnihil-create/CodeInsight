#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const ll mod=1000000007;
int main(void){
    ll H,W;
    cin>>H>>W;
    ll ans;
    if(H*W%3==0) ans=0;
    else{
        ans=min(H,W);
        ll a,b,c,w;
        a=W/3*H;
        w=W-W/3;
        b=H/2*w,c=(H-H/2)*w;
        ans=min(ans,max({a,b,c})-min({a,b,c}));
        
        a=(W/3+1)*H;
        w=W-W/3-1;
        b=H/2*w,c=(H-H/2)*w;
        ans=min(ans,max({a,b,c})-min({a,b,c}));

        ll temp=H,
        H=W,W=temp;

        a=W/3*H;
        w=W-W/3;
        b=H/2*w,c=(H-H/2)*w;
        ans=min(ans,max({a,b,c})-min({a,b,c}));

        a=(W/3+1)*H;
        w=W-W/3-1;
        b=H/2*w,c=(H-H/2)*w;
        ans=min(ans,max({a,b,c})-min({a,b,c}));
    }
    cout<<ans<<endl;
}