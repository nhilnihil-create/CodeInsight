#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N)
  {
    cin >> a[i];
  }
  int dir = 0;
  int ans = 0;
  rep(i, N - 1)
  {
    if (dir == 0)
    {
      if (a[i] < a[i + 1])
      {
        dir = 1;
      }
      if (a[i] > a[i + 1])
      {
        dir = -1;
      }
    }
    else if ((dir == 1 && a[i] > a[i + 1]) || (dir == -1 && a[i] < a[i + 1]))
    {
      ans++;
      dir = 0;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}