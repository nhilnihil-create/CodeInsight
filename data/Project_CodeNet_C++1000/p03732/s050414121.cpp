#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, w;
  cin >> n >> w;
  int w1, v1;
  cin >> w1 >> v1;
  vector<vector<int>> v(4);
  v[0].push_back(v1);
  for (int i = 1; i < n; i++) {
    int wi, vi;
    cin >> wi >> vi;
    v[wi-w1].push_back(vi);
  }

  for (int i = 0; i < 4; i++) {
    sort(v[i].begin(), v[i].end(), greater<int>());
    for (int j = 1; j < v[i].size(); j++) {
      v[i][j] += v[i][j-1];
    }
    v[i].insert(v[i].begin(), 0);
  }

  long long a[4] = {w1, w1+1, w1+2, w1+3};
  int ans = 0;
  for (int i = 0; i < v[0].size(); i++) {
    for (int j = 0; j < v[1].size(); j++) {
      for (int k = 0; k < v[2].size(); k++) {
        for (int l = 0; l < v[3].size(); l++) {
          if (a[0]*i+a[1]*j+a[2]*k+a[3]*l <= w) {
            ans = max(ans, v[0][i]+v[1][j]+v[2][k]+v[3][l]);
          }
        }
      }
    }
  }
  cout << ans << endl;
}