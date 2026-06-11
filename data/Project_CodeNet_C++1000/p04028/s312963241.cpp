#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll kMod = 1e9 + 7;

ll dp[6000][6000];

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 0; j <= i; ++j)
    {
      if (j == 0)
      {
        dp[i][j] = dp[i - 1][j + 1] * 2 + dp[i - 1][j];
      }
      else
      {
        dp[i][j] = dp[i - 1][j + 1] * 2 + dp[i - 1][j - 1];
      }
      dp[i][j] %= kMod;
    }
  }
  cout << dp[n][s.length()] << endl;
}