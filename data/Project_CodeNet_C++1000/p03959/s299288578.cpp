#include <bits/stdc++.h>
using namespace std;
int N;
int64_t dp[100010][2];

void init()
{
  for (int i = 0; i < N; i++)
  {
    dp[i][0] = dp[i][1] = 1;
  }
}

int main()
{
  cin >> N;
  vector<int64_t> T(N), A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> T.at(i);
  }
  dp[0][0] = dp[0][1] = A[0];
  for (int i = 1; i < N; i++)
  {
    if (A[i] > A[i - 1])
    {
      dp[i][0] = dp[i][1] = A[i];
    }
    else
    {
      dp[i][1] = A[i];
    }
  }
  if (T[N - 1] < dp[N - 1][0] || dp[N - 1][1] < T[N - 1])
  {
    cout << 0 << endl;
    return 0;
  }
  dp[N - 1][0] = dp[N - 1][1] = T[N - 1];
  for (int i = N - 2; i >= 0; i--)
  {
    if (T[i] > T[i + 1])
    {
      if (T[i] < dp[i][0] || dp[i][1] < T[i])
      {
        cout << 0 << endl;
        return 0;
      }
      dp[i][0] = dp[i][1] = T[i];
    }
    else
    {
      int64_t mi = 1, ma = T[i];
      if (T[i] < dp[i][0])
      {
        cout << 0 << endl;
        return 0;
      }
      dp[i][0] = max(dp[i][0], (int64_t)1);
      dp[i][1] = min(dp[i][1], T[i]);
    }
  }
  const int64_t MOD = 1000000007;
  int64_t ans = 1;
  for (int i = 0; i < N; i++)
  {
    (ans *= (dp[i][1] - dp[i][0] + 1)) %= MOD;
  }
  cout << ans << endl;
}
