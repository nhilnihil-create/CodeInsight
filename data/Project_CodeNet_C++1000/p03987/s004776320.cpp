#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct node{ ll l,r;};


int main(){
    ll n;cin>>n;
    ll a[n+1],b[n+1];
    rep(i,1,n){
        cin>>a[i];
        b[a[i]]=i;
    }
    node no[n+1];
    rep(i,1,n){
        no[i].l=-1;
        no[i].r=-1;
    }
    ll l,r;
    ll ans=0;
    for(ll i=n;i>=1;i--){
        if(b[i]<n){
            if(no[b[i]+1].r==-1){
                r=b[i];
            }else{
                r=no[b[i]+1].r;
            }
        }else{
            r=b[i];
        }
        if(b[i]>1){
            if(no[b[i]-1].l==-1){
                l=b[i];
            }else{
                l=no[b[i]-1].l;
            }
        }else{
            l=b[i];
        }
        no[r].l=l;
        no[l].r=r;
        
        ans=ans+i*(b[i]-l+1)*(r-b[i]+1);
    }
    cout<<ans<<endl;
    return 0;
}

