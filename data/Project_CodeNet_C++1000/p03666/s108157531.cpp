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
    if((i%j+j)%j==0){
        return i/j;
    }else if(i>0){
        return i/j;
    }
    return i/j-1;
}

int main(){
    ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    if(c==d && c==0){
        if(a==b){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        ll i;
        i=waru((b-a+(n-1)*d),(c+d));
        ll s=c*i+(n-1-i)*(-d);
        if(0<=i && i<=n-1 && b-a<=s+(d-c)*(n-1)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}

