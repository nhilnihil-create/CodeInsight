#include <iostream>
#include <vector>

using namespace std;

long dp[100+1][2];

int main() {
  long N, P;
  cin >> N >> P;
  vector<long> a(N);
  for (long i = 0; i < N; i++) {
    cin >> a[i];
  }
  dp[0][0] = 1;
  dp[0][1] = 0;
  for (long i = 0; i < N; i++) {
    if (a[i] % 2 == 0) {
      dp[i+1][0] = dp[i][0]*2;
      dp[i+1][1] = dp[i][1]*2;
    } else {
      dp[i+1][0] = dp[i][0]+dp[i][1];
      dp[i+1][1] = dp[i][0]+dp[i][1];
    }
  }
  cout << dp[N][P] << endl;
  return 0;
}