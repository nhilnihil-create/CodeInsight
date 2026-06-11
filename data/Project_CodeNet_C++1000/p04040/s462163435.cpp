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
    ll H,W,A,B;
    cin>>H>>W>>A>>B;
    ll h=H-A-1;
    ll w=W-B-1;
    ll c=1;
    ll ww=W-1;
    for(ll i=0;h+ww-i>ww;i++) c=(c*(h+ww-i))%mod;
    for(ll i=2;i<=h;i++) c=(c*mod_pow(i,mod-2,mod))%mod;
    ll ans=c;
    ll sum=h+ww;
    ll cnt=A;
    ll a=A;
    for(ll i=0;i<w;i++){
        c=(c*mod_pow(sum-i,mod-2,mod))%mod;
        c=(c*(ww-i))%mod;
        ans=(ans+(c*(cnt%mod))%mod)%mod;
        cnt=(cnt*(a+1))%mod;
        cnt=(cnt*mod_pow(i+2,mod-2,mod))%mod;
        a++;
    }
    cout<<ans<<endl;
}