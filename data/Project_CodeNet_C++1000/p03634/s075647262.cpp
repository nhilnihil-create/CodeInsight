#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )
using P = pair<int, int>;

int N, Q, K;
vector<vector<P> > G;
vector<int> dist;

void dfs(int pre, int n, int c) {
  if ( dist[n] != -1 ) return;
  dist[n] = c;
  for ( P &p: G[n] ) {
    if ( pre == p.first ) continue;
    dfs(n, p.first, c+p.second);
  }
  return;  
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  G.resize(N);
  dist.resize(N, -1);  
  REP(i, N-1) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    G[a].push_back(P(b, c));
    G[b].push_back(P(a, c));
  }

  cin >> Q >> K;
  K--;
  dfs(-1, K, 0);
  while ( Q-- ) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << dist[x] + dist[y] << endl;    
  }

  return 0;
}
