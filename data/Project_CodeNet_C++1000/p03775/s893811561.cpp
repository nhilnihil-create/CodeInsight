#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int f(ll a, ll b)
{
  ll mx = max(a, b);
  int cnt = 0;
  while (mx)
  {
    mx /= 10;
    cnt++;
  }
  return cnt;
}

int main()
{
  ll n;
  cin >> n;
  int nn = (int)sqrt(n) + 1;
  int ans = 1e9;
  for (int i = 1; i <= nn; i++)
  {
    if (n % i == 0)
    {
      ll j = n / i;
      int cnt = f(i, j);
      ans = min(cnt, ans);
    }
  }
  cout << ans << endl;
  return 0;
}