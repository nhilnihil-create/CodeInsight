#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
using ll = long long;

signed main()
{
  int n;
  cin >> n;

  int ans = 1, mx = 0;
  for (int i = 1; i <= n; ++i) {
    int score = 0;

    int j = i;
    while (j % 2 == 0) {
      j /= 2;
      ++score;
    }

    if (score >= mx) {
      mx = score;
      ans = i;
    }
  }
  
  cout << ans << '\n';

  return (0);
}
