#include <bits/stdc++.h>

#define si(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

template<class T, class U> void chmax(T &a, U b) { if (a < b) a = b; }
template<class T, class U> void chmin(T &a, U b) { if (b < a) a = b; }

using ll = long long;
using ld = long double;
using namespace std;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s; cin >> s;

  int a, z;
  rep(i, si(s)) {
    if (s[i] == 'A') {
      a = i;
      break;
    }
  }

  rep3(i, si(s), 0) {
    if (s[i] == 'Z') {
      z = i;
      break;
    }
  }

  cout << z - a + 1 << endl;
  
  return (0);
}