#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<int> a(N), b(N), c(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i) >> b.at(i) >> c.at(i);
  }
  
  // 3次元DP表のマスを無限で初期化。
  // (選択出来る薬品数)*(Aの総量)*(Bの総量)
  const int inf = 100000000;
  vector<vector<vector<int>>> cost(41, vector<vector<int>>(10*40+1, vector<int>(10*40+1)));
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= 10*N; j++) {
      for (int k = 0; k <= 10*N; k++) {
        cost.at(i).at(j).at(k) = inf;
      }
    }
  }
  // 0*0*0の時のコストは0で確定(初期条件)
  cost.at(0).at(0).at(0) = 0;
  
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 10*N; j++) {
      for (int k = 0; k <= 10*N; k++) {
        if (cost.at(i).at(j).at(k) == inf) {
          continue;
        }
        else {
          cost.at(i+1).at(j).at(k) = min(cost.at(i+1).at(j).at(k), cost.at(i).at(j).at(k));
          cost.at(i+1).at(j+a.at(i)).at(k+b.at(i)) = min(cost.at(i+1).at(j+a.at(i)).at(k+b.at(i)), cost.at(i).at(j).at(k)+c.at(i));
        }
      }
    }
  }
  
  int ans = inf;
  for (int j = 1; j <= 10*N; j++) {
    for (int k = 1; k <= 10*N; k++) {
      if (j*Mb == k*Ma) {
        ans = min(ans, cost.at(N).at(j).at(k));
      }
    }
  }
  
  
  if (ans == inf) {
    cout << -1 << endl;
  }
  else {
    cout << ans << endl;
  }
}