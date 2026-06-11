#include <bits/stdc++.h>

using namespace std;

long long a[10];

int main()
{
  for (int i = 1; i <= 7; i++)
    cin >> a[i];
  long long ans = 2 * a[2];
  if (a[1] % 2 + a[4] % 2 + a[5] % 2 >= 2 && a[1] && a[4] && a[5]) {
    ans += 6;
    a[1]--;
    a[4]--;
    a[5]--;
  }
  ans += 4 * (a[1] / 2);
  ans += 4 * (a[4] / 2);
  ans += 4 * (a[5] / 2);
  cout << ans / 2;
  return 0;
}
