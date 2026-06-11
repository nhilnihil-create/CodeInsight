#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=9000000000000000000;
long double pi=3.14159265358979323846L;
double eps=1e-12;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll popcount(ll n){
    ll ret=0;
    while(n>0){
        ret+=n%2;
        n/=2;
    }
    return ret;
}
ll gya[1000010];
ll kai[1000010];
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    ll a,b;cin>>a>>b;
    ll h[n];rep(i,0,n)cin>>h[i];
    ll u=10000000000,d=0;
    while(u-d>1){
        ll mid=(u+d)/2;
        ll sum=0;
        rep(i,0,n){
            ll y=h[i]-mid*b;
            if(y<=0)continue;
            sum+=(y+a-b-1)/(a-b);
        }
        if(sum<=mid)u=mid;
        else d=mid;
    }
    cout<<u<<endl;
}


