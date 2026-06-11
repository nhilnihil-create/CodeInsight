#include <bits/stdc++.h>
using namespace std;
int DP[3010]; // 水+砂糖の重量がiの時の、砂糖の重量の最大値

void init()
{
  for (int i = 0; i < 3010; i++)
  {
    DP[i] = -1;
  }
  DP[0] = 0;
}

bool ok(int s, int w, int E)
{
  return (100 * s) <= (E * w);
}

bool gt(int sw, int s, int msw, int ms)
{
  return s * msw > ms * sw;
}

int main()
{
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  init();
  for (int i = 0; i <= F; i++)
  {
    if (DP[i] == -1)
      continue;
    if (i + 100 * A <= F)
      DP[i + 100 * A] = DP[i];
    if (i + 100 * B <= F)
      DP[i + 100 * B] = DP[i];
    if (i + C <= F && ok(DP[i] + C, i - DP[i], E))
      DP[i + C] = DP[i] + C;
    if (i + D <= F && ok(DP[i] + D, i - DP[i], E))
      DP[i + D] = DP[i] + D;
  }
  int ms = 0, msw = 100 * A;
  for (int i = 0; i <= F; i++)
  {
    if (DP[i] == -1)
      continue;
    if (gt(i, DP[i], msw, ms))
    {
      ms = DP[i];
      msw = i;
    }
  }
  cout << msw << ' ' << ms << endl;
}