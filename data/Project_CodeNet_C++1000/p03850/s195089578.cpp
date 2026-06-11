#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 58;

int main()
{
  int N, A[100000];
  char op[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    if(i > 0) cin >> op[i];
    cin >> A[i];
  }

  int64 dp[3] = {A[0], -INF, -INF};
  for(int i = 1; i < N; i++) {
    if(op[i] == '+') {
      dp[0] = max(dp[0], dp[1]) + A[i];
      dp[1] -= A[i];
      dp[2] += A[i];
    } else {
      dp[2] = max(dp[1], dp[2]) + A[i];
      dp[1] = max(dp[0], dp[1]) - A[i];
      dp[0] -= A[i];
    }
  }
  cout << max({dp[0], dp[1], dp[2]}) << endl;
}