#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll inf=1e18;

int main() {
  ll n,m;
  cin >> n >> m;
  vector<ll> d(n,inf);
  d[0]=0;
  vector<map<ll,ll>> e(n);
  for(ll i=0;i<m;i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    e[a][b]=-c;
  }
  
  for(ll loop=0;loop<n-1;loop++) {
    bool update=false;
    for(ll i=0;i<n;i++) {
      if(d[i]!=inf) {
        for(auto p:e[i]) {
          ll to=p.first;
          ll v=p.second;
          if(d[to]>d[i]+v) {
            d[to]=d[i]+v;
            update=true;
          }
        }
      }
    }
    if(!update) {
      break;
    }
  }
  vector<bool> neg(n,false);
  for(ll loop=0;loop<n;loop++) {
    bool update=false;
    for(ll i=0;i<n;i++) {
      if(d[i]!=inf) {
        for(auto p:e[i]) {
          ll to=p.first;
          ll v=p.second;
          if(d[to]>d[i]+v) {
            d[to]=d[i]+v;
            update=true;
            neg[to]=true;
          }
          if(neg[i]) {
            neg[to]=true;
          }
        }
      }
    }
    if(!update) {
      break;
    }
  }
  if(neg[n-1]) {
    cout << "inf" << endl;
  }
  else {
    cout << -d[n-1] << endl;
  }
}