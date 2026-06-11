#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

bool is_no_need(int num, vector<int>& A, int K)
{
  int ix = num - 1;
  int n = A.size();

  vector<int> v(A.begin(), A.begin() + ix);
  copy(A.begin() + ix + 1, A.end(), back_inserter(v));

  vector<vector<int>> dp(n, vector<int>(K + 5, false));
  dp[0][0] = 1;
  int M = v.size();
  for (int i = 0; i < M; ++i) {
    for (int sum = 0; sum <= K; ++sum) {
      dp[i + 1][sum] = dp[i][sum];
      if (sum - v[i] >= 0) {
        dp[i + 1][sum] |= dp[i][sum - v[i]];
      }
    }
  }
  bool ret = true;
  for (int sum = max(0, K - A[ix]); sum < K; ++sum) {
    if (dp[M][sum]) {
      ret = false;
      break;
    }
  }
  return ret;
}

int main()
{
  int N, K; scanf("%d %d", &N, &K);
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }

  sort(A.begin(), A.end());
  int high = N + 1, low = 0;
  while (high - low > 1) {
    int mid = (high + low) / 2;
    if (is_no_need(mid, A, K)) { low = mid; }
    else { high = mid; }
  }

  int ans = low;
  printf("%d\n", ans);
  return 0;
}
