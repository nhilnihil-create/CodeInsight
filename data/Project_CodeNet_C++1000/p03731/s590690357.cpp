#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  ll t, sum, ans;
  cin >> n >> t;
  vector<ll> T(n);
  for (int i = 0; i < n; i++)
  {
    cin >> T.at(i);
  }

  ans = sum = T.at(0);
  for (int i = 1; i < n; i++)
  {
    if (T.at(i) - sum >= t)
    {
      ans += t;
    }
    else if (T.at(i) - sum < t)
    {
      ans += T.at(i) - sum;
    }

    sum = T.at(i);
  }
  ans += t;
  cout << ans << endl;
}
