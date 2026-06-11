#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

mat e(1e5+10);
ll n;
vec f(1e5+10);

ll dfs(ll u) {
  for(ll&t:e[u]) {
    dfs(t);
    t=f[t];
  }
  sort(e[u].begin(),e[u].end());
  ll i=0;
  for(ll v:e[u]) {
    f[u]=max(f[u],(ll)(e[u].size()-i+v));
    i++;
  }
}

int main() {
  cin >> n;
  vec a(n);
  for(ll i=2;i<=n;i++) {
    ll tmp;
    cin >> tmp;
    e[tmp].push_back(i);
  }
  dfs(1);
  cout << f[1] << endl;
}