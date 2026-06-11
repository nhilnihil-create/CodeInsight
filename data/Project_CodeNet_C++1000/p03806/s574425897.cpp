#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(long long N, long long M_a, long long M_b, std::vector<long long> a,
           std::vector<long long> b, std::vector<long long> c) {
    // min cost for i'th chem with j grams of A and k grams of B
    vector<vector<vector<int>>> dp(41, vector<vector<int>>(401, vector<int>(401, 50000)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
      for (int costA = 0; costA <= 400; costA++) {
        for (int costB = 0; costB <= 400; costB++) {
	    if (dp[i][costA][costB] == 50000) continue;
	    dp[i+1][costA][costB] = min(dp[i+1][costA][costB], dp[i][costA][costB]);
	    dp[i+1][costA + a[i]][costB+b[i]] = min(dp[i+1][costA + a[i]][costB + b[i]], dp[i][costA][costB] + (int)c[i]);
        }
      }
    }
    int res = 50000;
    for (int ca = 1; ca < 401; ca++) {
      for (int cb = 1; cb < 401; cb++) {
	  if (ca * M_b == cb * M_a) res = min(res, dp[N][ca][cb]);
      }
    }
    if (res == 50000) cout << -1 << endl;
    else cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long N;
  scanf("%lld", &N);
  long long M_a;
  scanf("%lld", &M_a);
  long long M_b;
  scanf("%lld", &M_b);
  std::vector<long long> a(N);
  std::vector<long long> b(N);
  std::vector<long long> c(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
    scanf("%lld", &b[i]);
    scanf("%lld", &c[i]);
  }
  solve(N, M_a, M_b, std::move(a), std::move(b), std::move(c));
  return 0;
}
