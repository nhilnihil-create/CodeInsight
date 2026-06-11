#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, a, b, c, answer = 0;
  cin >> N >> M;
  vector<vector<long long>> d(N,vector<long long>(N,INT_MAX));
  long long e[N][N];
  while (M--) {
    cin >> a >> b >> c;
    d[--a][--b] = c;
    d[b][a] = c;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      e[i][j] = d[i][j];
    }
  }
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      answer += e[i][j] < INT_MAX && d[i][j] < e[i][j];
    }
  }
  cout << answer;
}