
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////////////////

int main(){fastio;
    ll n,k;cin>>n>>k;
    ll a[n],b[n];rep(i,0,n-1)cin>>a[i]>>b[i];
    ll p=0;
    ll ans=0;
    for(ll i=30;i>=0;i--){
        if(k&(1ll<<i)){
            p+=(1<<i)-1;
            ll sum=0;
            rep(j,0,n-1){
                if((p&a[j])==a[j])sum+=b[j];
            }
            Max(ans,sum);
            //cout<<p<<" "<<sum<<endl;
            p++;
        }
    }
    p=k;ll sum=0;
    rep(j,0,n-1){
        if((p&a[j])==a[j])sum+=b[j];
    }
    Max(ans,sum);
    cout<<ans<<endl;
    
    return 0;
}





