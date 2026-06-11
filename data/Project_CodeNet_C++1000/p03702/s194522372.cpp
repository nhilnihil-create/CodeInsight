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

ll waru(ll i,ll j){
    if(i%j==0){
        return i/j;
    }
    return 1+(i/j);
}
            
int main(){
    ll n,a,b;cin>>n>>a>>b;
    ll h[n];rep(i,0,n-1)cin>>h[i];
    ll x[n];
    ll sum;
    ll l=0;
    ll r=pow(10,9)+1;
    ll mid;
    while(r-l>1){
        mid=(r+l)/2;
        sum=0;
        rep(i,0,n-1){
            x[i]=h[i]-mid*b;
            if(x[i]<=0){
                continue;
            }else{
                sum+=waru(x[i],a-b);
            }
        }
        if(sum<=mid){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r<<endl;
    
    return 0;
}
