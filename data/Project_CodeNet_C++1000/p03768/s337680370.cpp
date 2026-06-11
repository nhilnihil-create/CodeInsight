#include <bits/stdc++.h>
using namespace std;

#define int long long
using P = pair<int, int>;

struct query {
  int u, d, c;  
};

int N, M;
vector<vector<int> > G;
int Q;
vector<query> queries;
vector<int> color;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> M;
  G.resize(N);
  color.resize(N, 0);
  
  for ( int i = 0; i < M; i++ ) {
    int a, b;
    cin >> a >> b;    
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);   
  }

  cin >> Q;
  queries.resize(Q);
  for ( int i = 0; i < Q; i++ ) {
    cin >> queries[i].u >> queries[i].d >> queries[i].c;
    queries[i].u--;
  }

  int now = Q-1;
  int dp[N][11];
  fill_n(*dp, N*11, 0);  
  while ( now >= 0 ) {    
    int u = queries[now].u, d = queries[now].d, c = queries[now].c;
    queue<P> que;
    que.push(P(u, d));
    while ( !que.empty() ) {
      P q = que.front(); que.pop();
      int v = q.first, dist = q.second;

      if ( dist >= 0 && dp[v][dist] == 0 ) {
	dp[v][dist] = c;	
      } else {
	continue;
      }

      que.push(P(v, dist-1));	
      for ( int i: G[v] ) {
	que.push(P(i, dist-1));	
      }      
    }
    now--;
  }

  for ( int i = 0; i < N; i++ ) {
    cout << dp[i][0] << endl;
  }
  
  return 0;
}
