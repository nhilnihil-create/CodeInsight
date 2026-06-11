#include <bits/stdc++.h>
using namespace std;
int64_t MAXA = 100000;
vector<int64_t> Count(MAXA + 1, 0);

int main()
{
  int64_t N, a, ans = 0, maxa = 0;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    Count.at(a)++;
    maxa = max(a, maxa);
  }
  int64_t l = 0, r = maxa;
  while (l < r)
  {
    for (int i = l; i <= r; i++) // 左から重複している数字を探す
    {
      if (Count.at(i) >= 2)
      {
        l = i;
        break;
      }
    }
    for (int i = r; i >= l; i--)
    {
      if (Count.at(i) >= 2)
      {
        r = i;
        break;
      }
    }
    int64_t m = min(Count.at(l), Count.at(r)) - 1;
    Count.at(l) -= m;
    Count.at(r) -= m;
  }
  if (l == r)
  {
    if (Count.at(l) % 2 == 0) // 別のカードも一枚減らす必要がある
      Count.at(l) = 0;
    else
      Count.at(l) = 1;
  }
  for (int i = 0; i <= maxa; i++)
    ans += Count.at(i);
  cout << ans << endl;
}
