#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
  int N, M, R; cin >> N >> M >> R;
  vector<int> r(R);
  vector<vector<int>> dist(N, vector<int> (N, INF));
  for(int i = 0; i < R; i++){
    cin >> r[i]; --r[i];
  }
  for(int i = 0; i < M; i++){
    int a, b, c; cin >> a >> b >> c; --a; --b;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  for(int i = 0; i < N; i++) dist[i][i] = 0;
  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  sort(r.begin(), r.end());
  int ans = 1e9;
  do{
    int ans1 = 0;
    for(int i = 1; i < R; i++){
      ans1 += dist[r[i - 1]][r[i]];
    }
    ans = min(ans, ans1);
  }while(next_permutation(r.begin(), r.end()));
  cout << ans << endl;
}