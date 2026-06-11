#include <bits/stdc++.h>
using namespace std;

int main()
{
// 前からGreedy
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i + 1];
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++)
  {
    ans += (a[i - 1] + a[i]) / 2;
    if((a[i - 1] + a[i]) % 2 == 0 || a[i] == 0)
    {
      a[i] = 0;
    }
    else
    {
      a[i] = 1;
    }
  }
    cout << ans << endl;
    return 0;
}