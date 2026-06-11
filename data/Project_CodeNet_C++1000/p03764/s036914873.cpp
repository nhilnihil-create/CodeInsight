#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

ll mod_pow(ll x,ll n,ll m){
    if(n==0) return 1;
    ll res=mod_pow(x*x%m,n/2,m);
    if(n&1) res=res*x%m;
    return res;
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> x(n),y(m);
    cinf(n,x);
    cinf(m,y);
    ll s=0;
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        ll k=((m-1)*(n-i-1)*(i+1))%mod;
        ll ss=((x[i+1]-x[i])*(y[1]-y[0]))%mod;
        s=(s+(k*ss)%mod)%mod;
    }
    ans=s;
    for(ll i=1;i<m-1;i++){
        ll before_edge=y[i]-y[i-1];
        ll after_edge=y[i+1]-y[i];
        ll before_cnt=(n*(m-i)*i)%mod;
        ll after_cnt=(n*(m-i-1)*(i+1))%mod;
        s=(s*after_edge)%mod;
        s=(s*after_cnt)%mod;
        s=(s*mod_pow(before_edge,mod-2,mod))%mod;
        s=(s*mod_pow(before_cnt,mod-2,mod))%mod;
        ans=(ans+s)%mod;
    }
    cout<<ans<<endl;
}