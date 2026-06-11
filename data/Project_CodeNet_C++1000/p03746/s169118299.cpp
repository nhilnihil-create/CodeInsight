#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n,m;
  cin >> n >> m;
  vector<set<ll>> E(n);
  for(ll i=0;i<m;i++) {
    ll a,b;
    cin >> a >> b;a--,b--;
    E[a].insert(b);
    E[b].insert(a);
  }
  deque<ll> q;
  set<ll> cnt;
  q.push_front(0);
  cnt.insert(0);
  while(1) {
    ll f=q.front();
    for(ll t:E[f]) {
      if(cnt.count(t)) continue;
      else {
        cnt.insert(t);
        f=t;
        break;
      }
    }
    if(f==q.front()) break;
    else q.push_front(f);
  }
  while(1) {
    ll f=q.back();
    for(ll t:E[f]) {
      if(cnt.count(t)) continue;
      else {
        cnt.insert(t);
        f=t;
        break;
      }
    }
    if(f==q.back()) break;
    else q.push_back(f);
  }
  cout << q.size() << endl;
  while(q.size()) {
    cout << q.front()+1;
    q.pop_front();
    if(q.size()) cout << " ";
  }
  cout << endl;
}