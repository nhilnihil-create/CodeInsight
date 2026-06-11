#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll w,h,n; cin>>w>>h>>n;
    ll ans,x1=0,x2=w,y1=0,y2=h;
    rep(i,n){
        ll x,y,a;
        cin>>x>>y>>a;
        if(a==1) x1=max(x1,x);
        if(a==2) x2=min(x2,x);
        if(a==3) y1=max(y1,y);
        if(a==4) y2=min(y2,y);
    }
    if(x1>=x2||y1>=y2) ans=0;
    else ans=(x2-x1)*(y2-y1);
    cout<<ans<<endl;
    return 0;
}