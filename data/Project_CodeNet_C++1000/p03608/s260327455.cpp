#include <bits/stdc++.h>
using namespace std;


int main() {

  int INF = 1000000001;

  int N, M, R;
  cin >> N >> M >> R;

  int d[201][201];
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i != j) {
        d[i][j] = INF;
      }
    }
  }

  vector<int> r(R);
  for (int i = 0; i < R; i++) {
    cin >> r[i];
  }
  
  sort(r.begin(),r.end());

  int A, B, C;
  for (int i = 1; i <= M; i++) {
    cin >> A >> B >> C;
    if (C < d[A][B]) {
      d[A][B] = C;
      d[B][A] = C;
    }
  }

  // ワーシャルフロイド
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
  
  int answer = INF;

  // たどる順番を探す
  do {
    int a_ = 0;
    for(int i = 0; i < R - 1; i++) {
      a_ += d[r[i]][r[i+1]];
    }
    answer = min(answer, a_);
  } while (next_permutation(r.begin(), r.end())); 

  cout << answer << endl;

  return 0;

}