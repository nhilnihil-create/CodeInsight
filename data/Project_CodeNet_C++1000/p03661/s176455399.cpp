#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &e : a)
    cin >> e;
  ll sunu = 0, kuma = 0;
  ll nmin = 1e17;
  ll sum = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += a[i];
  }
  for (int i = 0; i < n - 1; ++i)
  {
    sunu += a[i];
    kuma = sum - sunu;
    nmin = min(nmin, abs(sunu - kuma));
  }
  cout << nmin << endl;

  return 0;
}
