#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

const ll N=1e5+10;
vec v(N),d(N),c(N);
mat G(N),dp(N,vec(11));
ll n,m,q;

void dfs(ll f,ll td,ll tc) {
  if(td>=0&&!dp[f][td]) {
    dp[f][td]=tc;
    for(ll t:G[f]) {
      dfs(t, td-1,tc);
    }
  }
}

int main() {
  cin >> n >> m;
  for(ll i=0;i<m;i++) {
    ll a,b;
    cin >> a >> b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin >> q;
  for(ll i=0;i<q;i++) {
    cin >> v[i] >> d[i] >> c[i];
    v[i]--;
  }
  while(q--) {
    for(ll i=d[q];i>=0;i--) {
      dfs(v[q],i,c[q]);
    }
  }
  for(ll i=0;i<n;i++) cout << dp[i][0] << endl;
}