#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) (a)=max(a, b)
#define chmin(a, b) (a)=min(a, b)
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;


/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/

ll N, M;
vector<ll> g[MAX];
vector<ll> ps;
ll used[MAX];

void dfs(ll u) {
  used[u]=1;
  ps.push_back(u);
  
  for(auto v:g[u])
    if(!used[v]) {
      dfs(v);
      return;
    }
}


int main(void) {
  ll i, j, k;
  
  cin >> N >> M;
  
  for(i=0; i<M; i++) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  
  dfs(0);
  reverse(ps.begin(), ps.end());
  ps.pop_back();
  dfs(0);
  
  pt(ps.size());
  for(i=0; i<ps.size(); i++) pt(ps[i]+1);
  
}



