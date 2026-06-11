#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
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
ll inf=1000000000000000000;
double pi=2*acos(0);
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
ll gya[200010];
ll kai[200010];
ll m;
ll beki(ll n,ll k){
  ll ret=1;
  ll now=n;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=m;
    }
    now*=now;
    now%=m;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n){
  return beki(n,mod-2);
}
void nckinit(ll n){
  kai[0]=1;
  kai[1]=1;
  for(int i=2;i<=n;i++){
    kai[i]=kai[i-1]*i;
    kai[i]%=mod;
  }
  gya[n]=gyaku(kai[n]);
  for(int i=n-1;i>=1;i--){
    gya[i]=gya[i+1]*(i+1);
    gya[i]%=mod;
  }
  gya[0]=1;
}    
ll nck(ll n,ll k){
  if(k<0)return 0;
  if(k==0||n==k)return 1;
  ll ret=kai[n];
  ret*=gya[n-k];
  ret%=mod;
  ret*=gya[k];
  ret%=mod;
  return ret;
}
ll npk(ll n,ll k){
  if(k<0)return 0;
  if(k==0)return 1;
  ll ret=kai[n];
  ret*=gya[n-k];
  ret%=mod;
  return ret;
}
random_device rnd;
mt19937 mt(rnd());
uniform_real_distribution<double> ra(1,6);
ll par[800010];
ll len[800010];
ll ele[800010];
void init(ll n){
  for(int i=0;i<n;i++){
    par[i]=i;
    len[i]=0;
    ele[i]=1;
  }
}
ll root(ll n){
  if(par[n]==n)return n;
  return par[n]=root(par[n]);
}
void unit(ll a,ll b){
  a=root(a);
  b=root(b);
  if(a==b)return;
  if(len[a]<len[b]){
    par[a]=b;
    ele[b]+=ele[a];
  }
  else{
    par[b]=a;
    ele[a]+=ele[b];
    if(len[a]==len[b])len[a]++;
  }
}
struct edge{
  ll from,to,cost;
};
bool cmp(edge a,edge b){
  return a.cost<b.cost;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,l,t;cin>>n>>l>>t;
  ll x[n],w[n];
  ll cnt[3];
  cnt[1]=0;
  cnt[2]=0;
  ll num=-1;
  rep(i,0,n){
    cin>>x[i]>>w[i];
    cnt[w[i]]++;
    if(w[i]==1)num=i;
  }
  if(num==-1){
    rep(i,0,n){
      ll g=x[i]-t%l;
      g+=l;
      g%=l;
      cout<<g<<endl;
    }
    return 0;
  }
  ll now=num;
  ll u=t/l;
  ll r=w[num]+1;
  if(r==3)r=1;
  ll h=cnt[r]*u*2;
  now+=h;
  now%=n;
  ll ans[n];
  u=t%l;
  vector<ll> v;
  rep(i,0,2*n){
    ll ii=i%n;
    if(w[num]==w[ii])continue;
    ll k=x[ii];
    if(ii<num)k+=l;
    if(i>=n)k+=l;
    v.push_back(k);
  }
  sort(v.begin(),v.end());
  //cout<<v[0]<<" "<<v[1]<<endl;
  rep(i,0,v.size()){
    if((v[i]-x[num])<u*2)now++;
    else break;
  }
  now%=n;
 // cout<<now<<" ";
  ll b[n];
  ll ki=x[num]+u;
  ki%=l;
  rep(i,0,n){
    if(w[i]==1)b[i]=x[i]+u;
    else b[i]=x[i]-u+l;
    b[i]%=l;
    if(b[i]<ki)b[i]+=l;
  }
  sort(b,b+n);
  rep(i,0,n){
    ans[now]=b[i]%l;
    now++;
    now%=n;
  }
  rep(i,0,n)cout<<ans[i]<<endl;
}