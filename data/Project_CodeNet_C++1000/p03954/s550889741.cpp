//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
//#define i_7 998244353
ll i_7;
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
#define endl "\n"
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}


void mod_print(ll k){
    ll P=1000;
    rep(y,1,P){
        ll x=mod(y*k);
        if(x+P>=i_7){
            x-=i_7;
        }
        if(abs(x)<=P){
            cout<<x<<"/"<<y<<endl;
            return;
        }
    }
    cout<<"nun"<<endl;
}
//////////////////////////



int main(){fastio
    ll n;cin>>n;
    ll a[2*n-1];rep(i,0,2*n-2)cin>>a[i];
    ll ok=1,ng=n*2-1;
    while(abs(ok-ng)>1){
        ll m=(ok+ng)/2;
        bool b[2*n-1];
        rep(i,0,2*n-2)b[i]=a[i]>=m;
        //cout<<m<<":";
        //rep(i,0,2*n-2)cout<<b[i]<<" ";cout<<endl;
        
        bool pre=b[n-1];
        for(ll i=n-2;i>=0;i--){
            ll j=2*n-2-i;
            if(pre==b[i]||pre==b[j])break;
            pre=b[i];
        }
        if(pre)ok=m;
        else ng=m;
    }
    cout<<ok<<endl;
    
    return 0;
}
