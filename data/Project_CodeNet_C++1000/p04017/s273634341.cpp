#include <bits/stdc++.h>
using namespace std;
int LOG = 20;
int main(){
  int N;
  cin >> N;
  vector<int> x(N);
  for (int i = 0; i < N; i++){
    cin >> x[i];
  }
  int L;
  cin >> L;
  vector<vector<int>> next(LOG, vector<int>(N));
  for (int i = 0; i < N; i++){
    next[0][i] = upper_bound(x.begin(), x.end(), x[i] + L) - x.begin() - 1;
  }
  for (int i = 1; i < LOG; i++){
    for (int j = 0; j < N; j++){
      next[i][j] = next[i - 1][next[i - 1][j]];
    }
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    int a, b;
    cin >> a >> b;
    if (a > b){
      swap(a, b);
    }
    a--;
    b--;
    int ans = 0;
    for (int j = LOG - 1; j >= 0; j--){
      if (next[j][a] < b){
        ans += (1 << j);
        a = next[j][a];
      }
    }
    cout << ans + 1 << endl;
  }
}