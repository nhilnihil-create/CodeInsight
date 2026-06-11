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
    ll n,k;cin>>n>>k;
    ll a[n+1];
    rep(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool dp[2][n+2][k];
    rep(i,0,1){
        rep(j,0,n+1){
            rep(K,0,k-1){
                dp[i][j][K]=false;
            }
        }
    }
    rep(i,1,k-1){
        dp[0][0][i]=false;
        dp[1][n+1][i]=false;
    }
    dp[0][0][0]=true;
    dp[1][n+1][0]=true;
    rep(i,1,n){
        rep(j,0,k-1){
            if(j-a[i]<0){
                if(dp[0][i-1][j])dp[0][i][j]=true;
            }else{
                if(dp[0][i-1][j] || dp[0][i-1][j-a[i]])dp[0][i][j]=true;
            }
        }
    }
    for(ll i=n;i>=1;i--){
        rep(j,0,k-1){
            if(j-a[i]<0){
                if(dp[1][i+1][j])dp[1][i][j]=true;
            }else{
                if(dp[1][i+1][j] || dp[1][i+1][j-a[i]])dp[1][i][j]=true;
            }
        }
    }
    ll ans=n;
    rep(i,1,n){
        ll now=0;
        bool bol=false;
        for(ll j=k-1;j>=0;j--){
            if(!dp[1][i+1][j])continue;
            rep(K,max(now,k-j-a[i]),k-j-1){
                if(dp[0][i-1][K])bol=true;
            }
            now=k-j;
        }
        if(bol)ans--;
    }
    cout<<ans<<endl;
    
    return 0;
}



