#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;
typedef long long ll;

int n;
ll W;
ll w[110], v[110];
vector<ll> values[4];
ll sum[4][110];
void solve() {
  for (int i=0;i<n;i++) {
    ll diff = w[i] - w[0];
    values[diff].push_back(v[i]);
  }
  for (int i=0;i<4;i++) {
    values[i].push_back(0);
    sort(values[i].begin(), values[i].end(), greater<ll>());
  }
  for (int i=0;i<4;i++) {
    for (int j=0;j<values[i].size();j++) {
      sum[i][j+1] = sum[i][j] + values[i][j];
    }
  }
  ll maxVal = 0;
  for (int i=0;i<values[0].size();i++) {
    for (int j=0;j<values[1].size();j++) {
      for (int k=0;k<values[2].size();k++) {
        for (int l=0;l<values[3].size();l++) {
          if ((i+j+k+l) * w[0] + j + 2*k + 3*l <= W) {
            maxVal = max(maxVal, sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l]);
          }
        }
      }
    }
  }
  cout << maxVal << endl;
}

int main() {
  cin >> n >> W;
  for (int i=0;i<n;i++) {
    cin >> w[i] >> v[i];
  }
  solve();
}
