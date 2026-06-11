#include <bits/stdc++.h>
using namespace std;
int A, B, C, D, E, F, answ, anss;

bool check(int s, int w)
{
  return (s * 100 <= E * w) && (s * answ > anss * w);
}

int main()
{
  cin >> A >> B >> C >> D >> E >> F;
  vector<int64_t> W, S;
  A *= 100;
  B *= 100;
  for (int i = 0; i * A <= F; i++)
  {
    for (int j = 0; i * A + j * B <= F; j++)
    {
      W.push_back(i * A + j * B);
    }
  }
  for (int i = 0; i * C <= F; i++)
  {
    for (int j = 0; i * C + j * D <= F; j++)
    {
      S.push_back(i * C + j * D);
    }
  }
  anss = 0, answ = A;
  for (auto w : W)
  {
    for (auto s : S)
    {
      if (s + w > F)
        continue;
      if (check(s, w))
      {
        answ = w;
        anss = s;
      }
    }
  }
  cout << answ + anss << ' ' << anss << endl;
}