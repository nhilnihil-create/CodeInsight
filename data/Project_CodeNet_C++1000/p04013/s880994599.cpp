#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

ifstream fin("../data.txt");

int n, a, x, sum;
long long dp[51][51][2501];
long long ans;
vector<int> v;

int main() {

  cin >> n >> a;
  for (int p = 0; p < n; p++) {
    cin >> x;
    sum += x;
    v.push_back(x);
  }

  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= sum; k++) {
        dp[i+1][j][k] = dp[i][j][k];
        if (k - v[i] >= 0 && j > 0) {
          dp[i+1][j][k] += dp[i][j-1][k-v[i]];
        }
      }

  for (int i = 1; i <= n; i++) {
    if (a*i > 2500) break;
    ans += dp[n][i][a*i];
  }

  cout << ans;

  return 0;
}
