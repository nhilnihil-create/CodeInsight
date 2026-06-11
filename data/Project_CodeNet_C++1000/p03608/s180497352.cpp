// ワーシャルフロイドからの全探索でオあり
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N, M, R;
  long long ans = 100100100100100100;
  cin >> N >> M >> R;
  vector<int> r(R);
  for(int i=0;i<R;i++) {
    cin >> r[i];
    r[i]--;
  }
  vector<vector<long long>> d(N, vector<long long>(N));
  for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
    if(i == j) d[i][j] = 0;
    else d[i][j] = 100100100100100100;
  }
  for(int i=0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    d[a][b] = c;
    d[b][a] = c;
  }
  for(int k=0;k<N;k++) for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
    if(d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
  }
  sort(r.begin(), r.end());
  do {
    long long total = 0;
    for(int i=0;i<R-1;i++) {
      total += d[r[i]][r[i+1]];
    }
    if(total < ans) ans = total;
  } while(next_permutation(r.begin(), r.end()));

  cout << ans << endl;
}
