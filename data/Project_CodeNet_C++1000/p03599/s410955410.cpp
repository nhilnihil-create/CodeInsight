#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  vector<int64_t> DP(3010, -1);
  A *= 100;
  B *= 100;
  DP.at(0) = 0;
  for (int w = 1; w <= F; w++) // 全量wにおける砂糖の重量sの最大値を求める
  {
    int64_t s = -1, a = -1, b = -1, c = -1, d = -1; // -1は実現不可能性を示す
    if (w - A >= 0 && DP.at(w - A) != -1)
    {
      a = DP.at(w - A);
      s = a;
    }
    if (w - B >= 0 && DP.at(w - B) != -1)
    {
      b = DP.at(w - B);
      if (b > s)
        s = b;
    }
    if (w - C >= 0 && DP.at(w - C) != -1)
    {
      int64_t sugar = DP.at(w - C) + C;
      if (100 * sugar <= (w - sugar) * E && ((w - sugar) % A) % B == 0)
        c = sugar;
      if (c > s)
        s = c;
    }
    if (w - D >= 0 && DP.at(w - D) != -1)
    {
      int64_t sugar = DP.at(w - D) + D;
      if (100 * sugar <= (w - sugar) * E && ((w - sugar) % A) % B == 0)
        d = sugar;
      if (d > s)
        s = d;
    }
    DP.at(w) = s;
  }
  int64_t s = 0, sw = 0;
  long double maxp = 0, p = 0;
  for (int i = 1; i <= F; i++)
  {
    if (DP.at(i) != -1)
    {
      long double dw = i;
      long double ds = DP.at(i);
      p = ds / dw;
      if (p >= maxp)
      {
        maxp = p;
        s = DP.at(i);
        sw = i;
      }
    }
  }
  cout << sw << ' ' << s << endl;
}
