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


int main(){
    ll n,ma,mb;cin>>n>>ma>>mb;
    ll a[n+1],b[n+1],c[n+1];
    rep(i,1,n){
        cin>>a[i]>>b[i]>>c[i];
    }
    ll dp[n+1][500][500];
    rep(i,0,n){
        rep(j,0,450){
            rep(k,0,450){
                dp[i][j][k]=inf;
            }
        }
    }
    dp[0][0][0]=0;
    rep(i,1,n){
        rep(j,0,440){
            rep(k,0,440){
                if(j-a[i]<0 || k-b[i]<0){
                    dp[i][j][k]=dp[i-1][j][k];
                    continue;
                }
                dp[i][j][k]=min(dp[i-1][j-a[i]][k-b[i]]+c[i],dp[i-1][j][k]);
                continue;
            }
        }
    }
    ll ans=inf;
    ll cc=1;
    while(ma*cc<=410 && mb*cc<=410){
        ans=min(ans,dp[n][ma*cc][mb*cc]);
        cc++;
    }
    if(ans<inf){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }
    
    return 0;
}
