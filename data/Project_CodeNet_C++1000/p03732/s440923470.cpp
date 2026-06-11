#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, W;
  cin >> N >> W;
  vector<long long> w(N), v(N);
  for (int i = 0; i < N; i++){
    cin >> w[i] >> v[i];
  }
  vector<vector<int>> v2(4);
  for (int i = 0; i < N; i++){
    v2[w[i] - w[0]].push_back(v[i]);
  }
  for (int i = 0; i < 4; i++){
    sort(v2[i].begin(), v2[i].end());
    reverse(v2[i].begin(), v2[i].end());
  }
  vector<vector<int>> sum(4);
  for (int i = 0; i < 4; i++){
    sum[i].push_back(0);
    for (int j = 0; j < v2[i].size(); j++){
      sum[i].push_back(sum[i].back() + v2[i][j]);
    }
  }
  int ans = 0;
  for (int i = 0; i <= v2[0].size(); i++){
    for (int j = 0; j <= v2[1].size(); j++){
      for (int k = 0; k <= v2[2].size(); k++){
        for (int l = 0; l <= v2[3].size(); l++){
          if (w[0] * i + (w[0] + 1) * j + (w[0] + 2) * k + (w[0] + 3) * l <= W){
            ans = max(ans, sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l]);
          }
        }
      }
    }
  }
  cout << ans << endl;
}