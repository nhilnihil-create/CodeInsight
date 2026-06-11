#include <cstdio>
#include <algorithm>

int dp[2][401][401];

struct med
{
  int a;
  int b;
  int c;
};

int main()
{
  int n, ma, mb;
  scanf("%d%d%d", &n, &ma, &mb);
  med m[40];
  for (int i = 0; i < n; ++i)
  {
    scanf("%d%d%d", &m[i].a, &m[i].b, &m[i].c);
  }
  std::fill((int*)dp, (int*)dp + 401 * 401 * 2, 1e9);
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j <= 400; ++j)
    {
      for (int k = 0; k <= 400; ++k)
      {
        if (j - m[i].a >= 0 && k - m[i].b >= 0)
        {
          dp[(i + 1) & 1][j][k] = std::min(dp[i & 1][j][k], dp[i & 1][j - m[i].a][k - m[i].b] + m[i].c);
        }
        else
        {
          dp[(i + 1) & 1][j][k] = dp[i & 1][j][k];
        }
      }
    }
  }
  int ans = 1e9;
  for (int i = ma, j = mb; i <= 400 && j <= 400; i += ma, j += mb)
  {
    ans = std::min(ans, dp[n & 1][i][j]);
  }
  printf("%d\n", ans == 1e9 ? -1 : ans);
  return 0;
}