#include<bits/stdc++.h>
using namespace std;

#define int long long
using P = pair<int, int>;

vector<int> G[100001];
int N;

int pre[100001];
int col[100001];

int bfs() {
  vector<bool> used(N, false);
  queue<P> q;
  q.push(P(0, 0));
  while ( !q.empty() ) {
    P p = q.front(); q.pop();
    int v = p.first, c = p.second;

    if ( v == N-1 ) return c;    
    
    if ( used[v] ) continue;
    used[v] = true;

    for ( int u : G[v] ) {
      if ( used[u] ) continue;      
      pre[u] = v;
      q.push(P(u, c+1));      
    }
  }
}

void bfs2() {
  vector<bool> used(N, false);
  queue<P> q;
  q.push(P(0, 0));
  while ( !q.empty() ) {
    P p = q.front(); q.pop();
    int v = p.first, c = p.second;   
    
    if ( used[v] ) continue;
    used[v] = true;
    col[v] = 1;    

    for ( int u : G[v] ) {
      if ( used[u] ) continue;		       
      if ( col[u] == 2 ) continue;      
      q.push(P(u, c+1));      
    }
  }
}

signed main() {
  cin >> N;
  for ( int i = 0; i < N-1; i++ ) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  
  int c = bfs();
  int now = N-1;
  int cnt = 0;
  
  while ( 1 ) {
    
    if ( cnt < (c+1)/2 ) {
      col[now] = 2;
      // cout << now << endl;
    } else {      
      col[now] = 1;      
    }
    cnt++;    
    if ( now == 0 ) break;
    now = pre[now];    
  }
  
  bfs2();
  int bl = 0;
  for ( int i = 0; i < N; i++ ) {
    if ( col[i] == 1 ) bl++;    
  }

  if ( bl > (N-bl) ) puts("Fennec");
  else puts("Snuke");  
  
  return 0;  
}
