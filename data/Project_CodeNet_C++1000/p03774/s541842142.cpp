#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
ll man(ll x1, ll y1, ll x2, ll y2)
{
  return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
  int N, M;
  cin >> N >> M;
  vector<ll> a(N), b(N), c(M), d(M);
  rep(i, N)
  {
    cin >> a[i] >> b[i];
  }
  rep(i, M)
  {
    cin >> c[i] >> d[i];
  }
  rep(i, N)
  {
    ll min;
    int num;
    rep(j, M)
    {
      if (j == 0)
      {
        min = man(a[i], b[i], c[j], d[j]);
        num = j + 1;
      }
      else
      {
        if (min > man(a[i], b[i], c[j], d[j]))
        {
          min = man(a[i], b[i], c[j], d[j]);
          num = j + 1;
        }
      }
    }
    cout << num << endl;
  }
  return 0;
}