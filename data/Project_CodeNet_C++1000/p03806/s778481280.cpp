//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
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
#define endl "\n"
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////



#define N 500
int main(){fastio
    ll n,ma,mb;cin>>n>>ma>>mb;
    ll dp[N][N];rep(i,0,N-1)rep(j,0,N-1)dp[i][j]=inf;
    dp[0][0]=0;
    while(n--){
        ll a,b,c;cin>>a>>b>>c;
        for(ll i=N-1;i>=0;i--){
            for(ll j=N-1;j>=0;j--){
                if(i-a>=0&&j-b>=0)Min(dp[i][j],dp[i-a][j-b]+c);
            }
        }
    }
    ll ans=inf;
    rep(i,1,N){
        if(ma*i<=N-1&&mb*i<=N-1)Min(ans,dp[ma*i][mb*i]);
    }
    if(ans>=inf/2)cout<<-1<<endl;
    else cout<<ans<<endl;
    
    return 0;
}
