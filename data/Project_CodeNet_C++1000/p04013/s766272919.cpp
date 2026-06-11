#include <bits/stdc++.h>
using namespace std;
int64_t DP[51][51][2510]; // i個目までの中から、j個選んだ時に、合計がkになる数

void init()
{
  for (int i = 0; i <= 50; i++)
  {
    for (int j = 0; j <= 50; j++)
    {
      for (int k = 0; k <= 2500; k++)
      {
        DP[i][j][k] = 0;
      }
    }
  }
}

int main()
{
  int64_t N, A, ans = 0;
  cin >> N >> A;
  init();
  DP[0][0][0] = 1;
  vector<int64_t> X(N + 1, 0);
  for (int i = 1; i <= N; i++)
    cin >> X.at(i);
  for (int i = 1; i <= N; i++) // 全部でi個
  {
    for (int j = 0; j <= i; j++) // i個から選ぶ数がj個
    {
      for (int k = 0; k <= 2500; k++)
      {
        if (j >= 1 && k >= X.at(i))
          DP[i][j][k] = DP[i - 1][j - 1][k - X.at(i)] + DP[i - 1][j][k];
        else
          DP[i][j][k] = DP[i - 1][j][k];
      }
    }
  }
  for (int j = 1; j <= N; j++)
    ans += DP[N][j][A * j];
  cout << ans << endl;
}
