#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18;


int main() {
  ll n,m;
  cin>>n>>m;
  vector<ll> a(m);
  vector<ll> b(m);
  vector<ll> c(m);
  rep(i,m){
    ll c1;
    cin>>a[i];
    a[i]--;
    cin>>b[i];
    b[i]--;
    cin>>c1;
    c[i]=-c1;
  }
  vector<ll> d(n);
  rep(i,n)d[i]=INF;
  d[0]=0;
  rep(i,n){
    rep(j,m){
    if (d[a[j]]==INF)continue;
    d[b[j]]=min(d[b[j]], d[a[j]]+c[j]);
    }
  }
  vector<ll> neg(n,0);
  rep(i,n){
    rep(j,m){
      if (d[a[j]]==INF)continue;
      if (d[b[j]]>d[a[j]]+c[j]){
        d[b[j]]=d[a[j]]+c[j];
        neg[b[j]]=-1;
      }
      if (neg[a[j]]==-1) neg[b[j]]=-1;
      }
    }

  if (neg[n-1]==-1)cout<<"inf";
  else cout<<-d[n-1];




}
