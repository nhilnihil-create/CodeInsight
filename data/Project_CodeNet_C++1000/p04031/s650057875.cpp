#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{

  int n;
  cin >> n;

  int a[n];

  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll min = LONG_MAX;
  ll tmp = 0;

  for (int i = -100; i <= 100; i++)
  {
    tmp = 0;

    for (int j = 0; j < n; j++)
      tmp += (a[j] - i) * (a[j] - i);

    if (min > tmp)
      min = tmp;
  }

  ll ans = min;

  cout << ans << endl;
}
