#include <bits/stdc++.h>
using namespace std;
int64_t DP[110][110][310]; // i番目までにj個選び、+αがkのときの価値の最大値

void init()
{
  for (int i = 0; i < 110; i++)
    for (int j = 0; j < 110; j++)
      for (int k = 0; k < 310; k++)
        DP[i][j][k] = -1;
  DP[0][0][0] = 0;
}

int main()
{
  int64_t N, W;
  cin >> N >> W;
  vector<int64_t> w(N), v(N);
  for (int i = 0; i < N; i++)
  {
    cin >> w.at(i) >> v.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      for (int k = 0; k <= 300; k++)
      {
        if (DP[i][j][k] == -1)
          continue;
        DP[i + 1][j][k] = max(DP[i + 1][j][k], DP[i][j][k]);
        DP[i + 1][j + 1][k + (w[i] - w[0])] = max(DP[i + 1][j + 1][k + (w[i] - w[0])], DP[i][j][k] + v[i]);
      }
    }
  }
  int64_t ans = 0;
  for (int j = 0; j <= N; j++)
  {
    for (int k = 0; k <= 300; k++)
    {
      if (w[0] * j + k <= W)
        ans = max(ans, DP[N][j][k]);
    }
  }
  cout << ans << endl;
}