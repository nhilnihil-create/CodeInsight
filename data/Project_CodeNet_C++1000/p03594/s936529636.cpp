
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll inf=(ll)1E17;

#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////////////////

string b="RYGB";


int main(){fastio;
    ll h,w,d;cin>>h>>w>>d;
    ll a[h+1][w];
    if(d%2==1){
        rep(i,0,h-1)rep(j,0,w-1){
            a[i][j]=(i+j)%2;
        }
    }else{
        rep(i,0,h)rep(j,0,w-1){
            if((i+j)%2==0)continue;
            ll x=(i+j)/d%2;
            ll y=(i-j+inf)/d%2;
            a[i][j]=x*2+y;
        }
        rep(i,0,h-1)rep(j,0,w-1){
            if((i+j)%2==1)continue;
            a[i][j]=a[i+1][j];
        }
        
    }
    /*rep(i,0,h-1){
        rep(j,0,w-1){
            cout<<a[i][j];
        }cout<<endl;
    }*/
    
    rep(i,0,h-1){
        rep(j,0,w-1){
            rep(k,0,3){
                if(a[i][j]==k){
                    cout<<b[k];
                }
            }
        }cout<<endl;
    }
    
    return 0;
}






