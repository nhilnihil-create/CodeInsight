#include <bits/stdc++.h>
using namespace std;
const int64_t INF = (1LL << 62);
int64_t dp[45][410][410]; // i番目にj:kとなる場合の最小コスト

int main()
{
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i] >> B[i] >> C[i];
  }
  for (int i = 0; i < 45; i++)
  {
    for (int j = 0; j < 410; j++)
    {
      for (int k = 0; k < 410; k++)
      {
        dp[i][j][k] = INF;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 410; j++)
    {
      for (int k = 0; k < 410; k++)
      {
        if (dp[i][j][k] == INF)
          continue;
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        dp[i + 1][j + A[i]][k + B[i]] = min(dp[i + 1][j + A[i]][k + B[i]], dp[i][j][k] + C[i]);
      }
    }
  }
  int64_t ans = INF;
  for (int i = 1; i < 400; i++)
  {
    if (Ma * i > 400 || Mb * i > 400)
      continue;
    ans = min(ans, dp[N][Ma * i][Mb * i]);
  }
  cout << (ans == INF ? -1 : ans) << endl;
}