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
//void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////

int main(){fastio
    ll n;cin>>n;
    ll c[n];
    string s;string debri;
    rep(i,0,n-1){
        cin>>c[i];
        if(i!=n-1){
            cin>>debri;
            s+=debri;
        }
    }
    if(n==1){
        cout<<c[0]<<endl;return 0;
    }
    rep(i,0,n-2){
        if(s[i]=='-')break;
        if(i==n-2){
            ll ans=0;rep(i,0,n-1)ans+=c[i];
            cout<<ans<<endl;return 0;
        }
    }
    ll spos=0;
    ll anspre=c[0];
    rep(i,0,n-2){
        if(s[i]=='+'){
            anspre+=c[i+1];
        }else{
            spos=i+1;
            break;
        }
    }
    vector<ll>a,b;
    while(spos<=n-1){
        a.pb(c[spos]);//s[i-1]=='='
        spos++;
        ll sum=0;
        while(spos<=n-1&&s[spos-1]=='+'){
            sum+=c[spos];
            spos++;
        }
        b.pb(sum);
    }
    //for(auto x:a)cout<<x<<" ";cout<<endl;
    //for(auto x:b)cout<<x<<" ";cout<<endl;
    ll vs=a.size();
    ll xs[vs],ys[vs];
    xs[0]=0;
    rep(i,1,vs-1){
        xs[i]=xs[i-1]+b[i-1]-a[i-1];
    }
    ys[vs-1]=0;
    for(ll i=vs-2;i>=0;i--){
        ys[i]=ys[i+1]+a[i+1]+b[i+1];
    }
    //rep(i,0,vs-1)cout<<xs[i]<<" ";cout<<endl;
    //rep(i,0,vs-1)cout<<ys[i]<<" ";cout<<endl;
    ll ans=-inf;
    rep(i,0,vs-1){
        Max(ans,xs[i]+ys[i]-a[i]-b[i]);
    }
    cout<<ans+anspre<<endl;
    
    return 0;
}
