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
ll clr[MAX];
ll mem[MAX][11];

void dfs(ll u, ll de, ll cl) {
  if(mem[u][de]) return;
  mem[u][de]=1;
  
  if(de==0) {clr[u]=cl; return;}
  
  
  dfs(u, de-1, cl);
  for(auto v:g[u]) dfs(v, de-1, cl);
  
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
  
  ll Q;
  cin >> Q;
  ll s[MAX], d[MAX], c[MAX];
  for(i=0; i<Q; i++) {
    cin >> s[i] >> d[i] >> c[i];
    s[i]--;
  }
  
  for(i=Q-1; i>=0; i--) dfs(s[i], d[i], c[i]);
  
  for(i=0; i<N; i++) pt(clr[i]);
}



