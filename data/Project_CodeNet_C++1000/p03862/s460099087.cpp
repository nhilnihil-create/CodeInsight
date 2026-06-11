#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;++i)
#define ocut cout
#define ouct cout
#define itn int

struct Union{
  vector<ll> par;
  Union(ll a){
  par=vector<ll>(a,-1);
  }
  ll find(ll a){
    if(par[a]<0){
      return a;
    }
    else{
      return par[a]=find(par[a]);
    }
  }
  bool same(ll a,ll b){
    return (find(a)==find(b));
  }
  ll size(ll a){
    return -par[find(a)];
  }
  void unite(ll a,ll b){
    ll c=find(a),d=find(b);
    if(c==d)
      return;
    if(size(c)<size(d)){
      swap(c,d);
    }
    par[c]+=par[d];
    par[d]=c;
  }
};
ll Nagaemon1;
void swap(ll i,ll j){
  Nagaemon1=i;
  i=j;
  j=Nagaemon1;
}
ll euclidean_gcd(ll a, ll b) {
  if(a < b) return euclidean_gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}
int main(void){
  ll n,x;
  cin >> n >> x;
  vector<ll> a(n);
  ll ans=0;
  rep(i,n){
    cin >> a[i];
    if(i>0){
      if(a[i]+a[i-1]>x){
        ans+=a[i]+a[i-1]-x;
        if(a[i]<a[i]+a[i-1]-x){
          a[i]=0;
          a[i-1]=x;
        }
        else a[i]-=a[i]+a[i-1]-x;
      }
    }
  }
  cout << ans;
}