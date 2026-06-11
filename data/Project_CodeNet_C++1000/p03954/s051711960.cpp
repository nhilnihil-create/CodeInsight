#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
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
ll inf=(ll)1E18;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int main(){fastio
    ll n;cin>>n;
    ll a[2*n-1];
    rep(i,0,2*n-2){
        cin>>a[i];
    }
    ll l=1,r=2*n;
    while(r-l>1){
        ll mid=(r+l)/2;
        bool b[2*n-1];
        rep(i,0,2*n-2){
            if(a[i]>=mid){
                b[i]=true;
            }else{
                b[i]=false;
            }
        }
        ll le=-1,ri=2*n-1;
        int bl=0,br=0;
        ll mi=n-1;
        for(ll i=mi-1;i>=0;i--){
            if(b[i] && b[i+1]){
                le=i+1;
                bl=1;
                break;
            }else if(!b[i] && !b[i+1]){
                le=i+2;
                bl=0;
                break;
            }else if(b[i] && !b[i+1]){
                le=i;
            }
        }
        for(ll i=mi+1;i<=2*n-2;i++){
            if(b[i] && b[i-1]){
                ri=i-1;
                br=1;
                break;
            }else if(!b[i] && !b[i-1]){
                ri=i-2;
                br=0;
                break;
            }else if(b[i] && !b[i-1]){
                ri=i;
            }
        }
        bool res=true;
        if(bl && br){
            res=true;
        }else if(!bl && !br){
            if(le==0 && ri==2*n-2){
                res=true;
            }else{
                res=false;
            }
        }else if(bl && !br){
            ll k=(ri+le)/2;
            if(mi<=k){
                res=true;
            }else{
                res=false;
            }
        }else if(!bl && br){
            ll k=(ri+le)/2;
            if(k<=mi){
                res=true;
            }else{
                res=false;
            }
        }
        if(res){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<l<<endl;
    
    return 0;
}


