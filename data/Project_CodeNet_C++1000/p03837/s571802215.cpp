#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N, vector<int>(N, INF));
  for (int i = 0; i < M; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    E[a][b] = c;
    E[b][a] = c;
  }
  vector<vector<int>> d = E;
  for (int i = 0; i < N; i++){
    d[i][i] = 0;
  }
  for (int k = 0; k < N; k++){
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      if (E[i][j] != INF && d[i][j] != E[i][j]){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}