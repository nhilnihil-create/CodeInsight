#include <bits/stdc++.h>
using namespace std;
int64_t MOD = 1000000007;
int64_t DP[100][3][3]; // n, top, down (R, G, B)

int main()
{
  int64_t N, ans = 0;
  string f, s;
  cin >> N >> f >> s;
  for (int n = 0; n < N; n++)
  {
    if (f.at(n) == s.at(n)) // 縦に置かれている場合
    {
      if (n)
      {
        for (int i = 0; i < 3; i++)
        {
          for (int j = 0; j < 3; j++)
          {
            if (i != j)
            {
              DP[n][i][j] = 0;
              continue;
            }
            int64_t x = 0;
            for (int k = 0; k < 3; k++)
            {
              for (int m = 0; m < 3; m++)
              {
                if (k != i && m != i)
                {
                  x = (x + DP[n - 1][k][m]) % MOD;
                }
              }
            }
            DP[n][i][j] = x;
          }
        }
      }
      else
      {
        for (int i = 0; i < 3; i++)
        {
          for (int j = 0; j < 3; j++)
          {
            if (i != j)
              DP[0][i][j] = 0;
            else
              DP[0][i][j] = 1;
          }
        }
      }
    }
    else // 横に置かれている場合
    {
      if (n)
      {
        for (int i = 0; i < 3; i++)
        {
          for (int j = 0; j < 3; j++)
          {
            if (i == j)
            {
              DP[n][i][j] = 0;
              DP[n + 1][i][j] = 0;
              continue;
            }
            int64_t x = 0;
            for (int k = 0; k < 3; k++)
            {
              for (int m = 0; m < 3; m++)
              {
                if (k == m)
                {
                  if (k != i && k != j)
                  {
                    x += DP[n - 1][k][m];
                  }
                }
                else
                {
                  if (i != k && j != m)
                  {
                    x += DP[n - 1][k][m];
                  }
                }
              }
            }
            DP[n][i][j] = x;
            DP[n + 1][i][j] = x;
          }
        }
      }
      else
      {
        for (int i = 0; i < 3; i++)
        {
          for (int j = 0; j < 3; j++)
          {
            if (i == j)
            {
              DP[n][i][j] = 0;
              DP[n + 1][i][j] = 0;
            }
            else
            {
              DP[n][i][j] = 1;
              DP[n + 1][i][j] = 1;
            }
          }
        }
      }
      n++;
    }
  }
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      ans = (ans + DP[N - 1][i][j]) % MOD;
    }
  }
  cout << ans << endl;
}