#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
ll inf=1000000000000000000;
double pi=acos(-1.0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
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
    ios::sync_with_stdio(false);cin.tie(0);
    ll n;cin>>n;
    ll aa;cin>>aa;
    vector<ll> v;
    v.push_back(aa);
    rep(i,0,n-1){
        char c;cin>>c;
        ll a;cin>>a;
        if(c=='+')v.push_back(a);
        else v.push_back(-a);
    }
    ll c=0;
    vector<ll> w;
    rep(i,0,n){
        if(v[i]<0)w.push_back(i);
    }
    ll sum[n+1];
    ll summ[n+1];
    sum[0]=0;
    summ[0]=0;
    rep(i,0,n){
        sum[i+1]=sum[i]+v[i];
        summ[i+1]=summ[i]+abs(v[i]);
    }
    ll ans=sum[n];
    if(w.size()==0){
        cout<<ans<<endl;
        return 0;
    }
    rep(i,0,w.size()-1){
        ll num=w[i];
        ll cnt=sum[num+1];
        cnt+=-(summ[w[i+1]]-summ[w[i]+1]);
        cnt+=summ[n]-summ[w[i+1]];
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}
