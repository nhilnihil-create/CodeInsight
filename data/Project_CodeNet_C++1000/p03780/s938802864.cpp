#include<iostream>
#include<vector>
#include<algorithm>

bool check(int mid, std::vector<int> &a, int K) {
  std::vector<std::vector<bool>> dp(a.size() + 1, std::vector<bool>(K, false));
  dp[0][0] = true;
  for (int i = 1; i <= (int) a.size(); ++i) {
    if (i - 1 == mid) {
      for (int j = 0; j < K; ++j) {
        dp[i][j] = dp[i - 1][j];
      }
      continue;
    }
    for (int j = 0; j < K; ++j) {
      dp[i][j] = dp[i - 1][j] || (j >= a[i - 1] ? dp[i - 1][j - a[i - 1]] : false);
    }
  }
  for (int i = std::max(K - a[mid], 0); i < K; ++i) {
    if (dp[a.size()][i]) { return true; }
  }
  return false;
}

int main() {
  int N, K;
  std::cin >> N >> K;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  int min = -1;
  int max = (int) a.size();
  while (max > min + 1) {
    auto mid = (min + max + 1) / 2;
    if (check(mid, a, K)) {
      max = mid;
    } else {
      min = mid;
    }
  }
  std::cout << max << std::endl;
  return 0;
}