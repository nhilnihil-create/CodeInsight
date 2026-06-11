
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
//#define i_7 998244353
//#define i_5 998244351
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
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
long double EPS=1E-8;
////////////////////////////////////////

#define N 100005
#define M 61
ll dp[N][M];

ll cal(ll pos,ll k){
    for(ll x=M-1;x>=0;x--){
        if((k>>x)&1LL){
            pos=dp[pos][x];
        }
    }
    return pos;
}

int main(){
    ll n;cin>>n;
    ll x[n];rep(i,0,n-1)cin>>x[i];
    ll m,k;cin>>m>>k;
    ll a[m];rep(i,0,m-1){cin>>a[i];a[i]--;}
    ll b[n-1];rep(i,0,n-2)b[i]=x[i+1]-x[i];
    ll c[n-1];rep(i,0,n-2)c[i]=i;
    rep(i,0,m-1){
        swap(c[a[i]-1],c[a[i]]);
    }
    rep(i,0,n-2){
        dp[i][0]=c[i];
    }
    rep(j,1,M-1){
        rep(i,0,n-2){
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    ll d[n-1];rep(i,0,n-2)d[i]=i;
    rep(i,0,n-2){
        d[i]=cal(i,k);
    }
    ll dis[n-1];
    rep(i,0,n-2){
        dis[i]=b[d[i]];
    }
    ll ans=x[0];
    cout<<ans<<endl;
    rep(i,1,n-1){
        ans+=dis[i-1];
        cout<<ans<<endl;
    }
    
    return 0;
}

