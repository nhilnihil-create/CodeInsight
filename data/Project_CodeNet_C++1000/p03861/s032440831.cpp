#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int, int>;

int main() {
  ull a, b, x;
  cin >> a >> b >> x;
  if (a == 0)
    cout << (b / x + 1) << endl;
  else
    cout << (b / x - (a - 1) / x) << endl;
  return 0;
}
