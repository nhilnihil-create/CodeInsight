#include <iostream>
#include <vector>
using namespace std;

int INF = 100000;

int min(int a, int b) {
  return a > b ? b : a;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M), c(M);
  int dist[100][100];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        dist[i][j] = 0;
      } else {
        dist[i][j] = INF;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
    dist[a[i]][b[i]] = c[i];
    dist[b[i]][a[i]] = c[i];
  }
  
  
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  
  int res = M;
  for (int k = 0; k < M; k++) {
    bool flag = false;
    for (int i = 0; i < N; i++) {
      if (dist[i][a[k]]+c[k] == dist[i][b[k]]) {
        flag = true;
      }
    }
    if (flag) res--;
  }
  cout << res << endl;
  return 0;
}