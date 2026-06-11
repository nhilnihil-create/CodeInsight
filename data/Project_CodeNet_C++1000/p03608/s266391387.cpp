#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int N,M,R;
int Graph[250][250];
int dist[250][250];


void dijkstra() {
  for (int i = 0; i < N; i++) {
    int nowd[N];
    for (int j = 0; j < N; j++) {
      nowd[j] = 99999999;
    }
    
    priority_queue<P, vector<P>, greater<P>> Q;
    while (!Q.empty()) {
      Q.pop();
    }
    Q.push(make_pair(0,i));
    while (!Q.empty()) {
      P p = Q.top();
      Q.pop();
      if (nowd[p.second] < p.first) {
        continue;
      }
      for (int j = 0; j < N; j++) {
        if (i == j) {
          continue;
        }
        if (nowd[j] > p.first + Graph[p.second][j]) {
          nowd[j] = p.first + Graph[p.second][j];
          Q.push(make_pair(p.first + Graph[p.second][j],j));
        }
      }
    }
    for (int j = 0; j < N; j++) {
      if (i == j) {
        dist[i][j] = 0;
      }
      dist[i][j] = nowd[j];
    }
  }
}

int main() {
  cin >> N >> M >> R;
  int r[R];
  for (int i = 0; i < R; i++) {
    cin >> r[i];
    r[i]--;
  }
  sort(r,r+R);
  for (int i = 0; i < 250; i++) {
    for (int j = 0; j < 250; j++) {
      Graph[i][j] = 99999999;
      dist[i][j] = 99999999;
    }
  }
  for (int i = 0; i < 250; i++) {
    Graph[i][i] = 0;
  }
  for (int i = 0; i < M; i++) {
    int a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    Graph[a][b] = c;
    Graph[b][a] = c;
  }
  
  dijkstra();
  
  int ans = 99999999;
  do {
    int result = 0;
    for (int i = 1; i < R; i++) {
      result += dist[r[i-1]][r[i]];
    }
    ans = min(ans,result);
} while(next_permutation(r,r + R));
  cout << ans << endl;
  return 0; 
}