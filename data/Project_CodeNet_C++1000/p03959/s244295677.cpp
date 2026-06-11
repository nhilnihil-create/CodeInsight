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


int main(){
    ll n;cin>>n;
    ll t[n],a[n];
    rep(i,0,n-1)cin>>t[i];
    rep(i,0,n-1)cin>>a[i];
    if(n==1){
        if(a[0]==t[0]){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
        return 0;
    }
    ll ans[n];rep(i,0,n-1)ans[i]=0;
    ans[0]=t[0];
    rep(i,1,n-1){
        if(t[i]!=t[i-1]){
            ans[i]=t[i];
        }
    }
    if(ans[n-1]!=0 && ans[n-1]!=a[n-1]){
        cout<<0<<endl;
        return 0;
    }
    ans[n-1]=a[n-1];
    for(ll i=n-2;i>=0;i--){
        if(a[i]<ans[i]){
            cout<<0<<endl;
            return 0;
        }
        if(a[i]!=a[i+1]){
            if(ans[i]==0){
                ans[i]=a[i];
            }else if(ans[i]==a[i]){
                continue;
            }else{
                cout<<0<<endl;
                return 0;
            }
        }
    }
    ll x=1;
    rep(i,0,n-1){
        if(ans[i]!=0){
            continue;
        }
        x=(x*min(t[i],a[i]))%i_7;
    }
    //rep(i,0,n-1)cout<<ans[i]<<' ';
    cout<<x<<endl;
    
    return 0;
}

