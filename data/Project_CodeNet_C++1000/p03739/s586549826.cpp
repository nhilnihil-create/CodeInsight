#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, s = 0, cnt = 0, ans;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  bool pos = true;
  for (int i = 0; i < N; i++)
  {
    s += A.at(i);
    if (pos && s <= 0)
    {
      cnt += (1 - s);
      s = 1;
    }
    else if (!pos && s >= 0)
    {
      cnt += (s + 1);
      s = -1;
    }
    pos = !pos;
  }
  ans = cnt, cnt = 0, s = 0, pos = false;
  for (int i = 0; i < N; i++)
  {
    s += A.at(i);
    if (pos && s <= 0)
    {
      cnt += (1 - s);
      s = 1;
    }
    else if (!pos && s >= 0)
    {
      cnt += (s + 1);
      s = -1;
    }
    pos = !pos;
  }
  cout << min(cnt, ans) << endl;
}
