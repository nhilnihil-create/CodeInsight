//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
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
typedef pair<dd,dd> d_d;
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
#define fi first
#define se second
///////////////////////////

ll ask(ll n){
    cout<<"? "<<n<<endl;
    fflush(stdout);
    string s;cin>>s;
    if(s[0]=='Y')return 0;
    else return 1;
}
void sayans(ll ans){
    cout<<"! "<<ans<<endl;
    fflush(stdout);
}
bool normal(ll keta){
    ll ok=(ll)powl(10,keta);
    ll ng=(ll)powl(10,keta-1);
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(ask(mid*10)==0){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    sayans(ok);
    return 0;
}

int main(){fastio
    rep(i,1,10){
        ll t=(ll)powl(10,i);
        ll res=ask(t);
        if(res==1){
            normal(i);
            return 0;
        }
    }
    rep(i,0,9){
        ll t=2*(ll)powl(10,i);
        ll res=ask(t);
        if(res==0){
            sayans(t/2);
            return 0;
        }
    }
    
    return 0;
}
