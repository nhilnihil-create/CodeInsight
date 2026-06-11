#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// dp[i][k][sum] := 先頭からi番目までの数字から k 枚選んだとき,
// 選んだ数字の総和を s にできる場合の数
long long dp[55][55][3000] = {0};

int main() {
  int n, a;
  cin >> n >> a;

  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  dp[0][0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int k = 0; k <= i; k++) {
      for (int sum = 0; sum <= 2500; sum++) {
        if (i > 0 && sum - x[i-1] < 0) {
          dp[i][k][sum] = dp[i - 1][k][sum];
        }
        if (i > 0 && k > 0 && sum - x[i-1] >= 0) {
          dp[i][k][sum] = dp[i - 1][k][sum] + dp[i - 1][k - 1][sum - x[i-1]];
        }
      }
    }
  }

  long long ans = 0;
  for (int k = 1; k <= n; k++) {
    ans += dp[n][k][k * a];
  }
  cout << ans << endl;

  return 0;
}