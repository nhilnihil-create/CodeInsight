#include <bits/stdc++.h>

#define FOR(i, a, b)  for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << "\n"
#define _ << " _ " <<
#define ll long long

using namespace std;

bool pitaj(ll x) {
  cout << "? " << x << "\n";
  char t;
  cin >> t;
  return (t == 'Y');
}

int main() {
  ios_base::sync_with_stdio(false);

  bool A = pitaj(1000000000);
  if (A) {
    ll x = 1;
    while (!pitaj(2 * x)) {x *= 10;}
    cout << "! " << x << "\n";
  } else {
    ll x = 1;
    while (pitaj(x)) {
      x *= 10;
    }
    x /= 10;
    ll lo = x, hi = x * 10 - 1;
    while (lo < hi) {
      ll mi = lo + (hi - lo) / 2;
      bool b = pitaj(10 * mi);
      if (b) {
        hi = mi;
      } else {
        lo = mi + 1;
      }
    }
    cout << "! " << lo << "\n";
  }

  return 0;
}
