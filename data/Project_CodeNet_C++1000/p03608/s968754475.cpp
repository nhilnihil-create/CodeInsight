#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> r(R);
  for (int i = 0; i < R; i++){
    cin >> r[i];
    r[i]--;
  }
  vector<vector<int>> d(N, vector<int>(N, INF));
  for (int i = 0; i < N; i++){
    d[i][i] = 0;
  }
  for (int i = 0; i < M; i++){
    int A, B, C;
    cin >> A >> B >> C;
    A--;
    B--;
    d[A][B] = C;
    d[B][A] = C;
  }
  for (int k = 0; k < N; k++){
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int ans = INF;
  vector<int> p(R);
  for (int i = 0; i < R; i++){
    p[i] = i;
  }
  while (1){
    int tmp = 0;
    for (int i = 0; i < R - 1; i++){
      tmp += d[r[p[i]]][r[p[i + 1]]];
    }
    ans = min(ans, tmp);
    if (!next_permutation(p.begin(), p.end())){
      break;
    }
  }
  cout << ans << endl;
}