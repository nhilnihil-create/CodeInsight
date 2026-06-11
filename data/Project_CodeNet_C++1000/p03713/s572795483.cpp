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
////////////////////////////

ll Max(ll *a){
    ll maxi=-1;
    rep(i,0,2){
        maxi=max(maxi,a[i]);
    }
    return maxi;
}
ll Min(ll *a){
    ll mini=inf;
    rep(i,0,2){
        mini=min(mini,a[i]);
    }
    return mini;
}


int main(){
    ll h,w,i,j;cin>>h>>w;
    if(h%3==0 || w%3==0){
        cout<<0<<endl;
        return 0;
    }
    ll ans=min(h,w);
    j=w/2;
    ll s[3];
    rep(i,0,h){
        s[0]=i*w;
        s[1]=(h-i)*j;
        s[2]=(h-i)*(w-j);
        ans=min(ans,Max(s)-Min(s));
    }
    i=h/2;
    rep(j,0,w){
        s[0]=h*j;
        s[1]=(w-j)*i;
        s[2]=(w-j)*(h-i);
        ans=min(ans,Max(s)-Min(s));
    }
    cout<<ans<<endl;
    
    
    return 0;
}
