#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector<ll> a(3 * N);
  rep(i, 3 * N)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  int count = 0;
  for (int i = N; i < 3 * N; i++)
  {
    if (count % 2 == 0)
    {
      ans += a[i];
    }
    count++;
  }
  cout << ans << endl;
  return 0;
}