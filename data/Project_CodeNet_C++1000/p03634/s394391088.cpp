#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n;
  cin >> n;
  vector<map<ll,ll>> G(n);
  for(ll i=0;i<n-1;i++) {
    ll a,b,c;
    cin >> a >> b >> c;
    a--,b--;
    G[a][b]=c;
    G[b][a]=c;
  }
  ll Q,k;
  cin >> Q >> k;
  k--;
  vec d(n,-1);
  priority_queue<pll,vector<pll>,greater<pll>> q;
  q.push({0,k});
  while(q.size()) {
    ll f=q.top().second;
    ll fd=q.top().first;
    q.pop();
    if(d[f]>-1) continue;
    d[f]=fd;
    for(auto p:G[f]) {
      ll t=p.first;
      ll td=fd+p.second;
      q.push({td,t});
    }
  }
  while(Q--) {
    ll x,y;
    cin >> x >> y;
    x--,y--;
    cout << d[x]+d[y] << endl;
  }
}