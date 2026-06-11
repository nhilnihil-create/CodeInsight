#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

const int INF = INT_MAX / 2;

template <class T> inline bool chmin(T& a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> rs(R);
  for(int i = 0; i < R; ++i) {
    cin >> rs[i];
  }
  vector<vector<int>> d(N, vector<int>(N, INF));
  int a, b, c;
  for(int i = 0; i < M; ++i) {
    cin >> a >> b >> c;
    d[a - 1][b - 1] = c;
    d[b - 1][a - 1] = c;
  }
  for(int i = 0; i < N; ++i) {
    d[i][i] = 0;
  }

  for(int k = 0; k < N; ++k) {
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  // 最短距離はここで計算できた
  sort(rs.begin(), rs.end());
  int md = INF;
  do {
    int dd = 0;
    int p = rs[0];

    for(auto n : rs) {
      dd += d[p - 1][n - 1];
      p = n;
    }
    chmin(md, dd);
  } while(next_permutation(rs.begin(), rs.end()));

  cout << md << endl;
  return 0;
}