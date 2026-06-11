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
///////////////////////////
struct edge{ll from,to,cost;};


int main(){
    ll n,m;cin>>n>>m;
    edge e[m];
    rep(i,0,m-1)cin>>e[i].from>>e[i].to>>e[i].cost;
    ll dp[n+1];
    rep(i,1,n)dp[i]=-inf;
    dp[1]=0;
    bool update;
    bool n_update;
    ll c=0;
    while(true){
        update=false;
        n_update=false;
        c++;
        rep(i,0,m-1){
            if(dp[e[i].from]!=-inf && dp[e[i].to]<dp[e[i].from]+e[i].cost){
                update=true;
                dp[e[i].to]=dp[e[i].from]+e[i].cost;
                if(e[i].to==n)n_update=true;
                if(c>=n+2 && e[i].to==n){
                    cout<<"inf"<<endl;
                    return 0;
                }
            }
        }
        if(!update)break;
        if(c>=n+2 && !n_update)break;
    }
    //rep(i,1,n)cout<<dp[i]<<endl;
    cout<<dp[n]<<endl;
    
    return 0;
}
