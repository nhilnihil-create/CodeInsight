#include <bits/stdc++.h>

#define si(v) v.size()
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (n); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

using ll = long long;
using ld = long double;
using namespace std;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  char a, b; cin >> a >> b;
  if (a == b) cout << "H\n";
  else cout << "D\n";
  
  return (0);
}