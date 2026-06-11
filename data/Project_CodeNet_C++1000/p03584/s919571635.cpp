#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, ans = 0;
  cin >> N >> K;
  vector<int64_t> A(N), B(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i) >> B.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    bool ok = true;
    for (int j = 0; j <= 30; j++)
    {
      if (!(K & (1 << j)) && A.at(i) & (1 << j))
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      ans += B.at(i);
    }
  }
  for (int i = 30; i >= 0; i--)
  {
    int64_t k = K;
    if (!(k & (1 << i)))
      continue;
    k &= ~(1 << i);
    for (int j = i - 1; j >= 0; j--)
    {
      k |= (1 << j);
    }
    int64_t tmp = 0;
    for (int l = 0; l < N; l++)
    {
      bool ok = true;
      for (int m = 0; m <= 30; m++)
      {
        if (!(k & (1 << m)) && A.at(l) & (1 << m))
        {
          ok = false;
          break;
        }
      }
      if (ok)
      {
        tmp += B.at(l);
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
