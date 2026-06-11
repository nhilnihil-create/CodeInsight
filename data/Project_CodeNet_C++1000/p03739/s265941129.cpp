#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  vector<ll> csum;
  partial_sum(va.begin(), va.end(), back_inserter(csum));

  ll diff = 0, cnts = 0;
  for (int i = 0; i < n; ++i) {
    ll a = csum[i] + diff;
    if (i % 2 == 0 && a >= 0) {
      diff -= a + 1;
      cnts += a + 1;
    } else if (i % 2 == 1 && a <= 0) {
      diff += -a + 1;
      cnts += -a + 1;
    }
  }

  diff = 0;
  ll cnts2 = 0;
  for (int i = 0; i < n; ++i) {
    ll a = csum[i] + diff;
    if (i % 2 == 1 && a >= 0) {
      diff -= a + 1;
      cnts2 += a + 1;
    } else if (i % 2 == 0 && a <= 0) {
      diff += -a + 1;
      cnts2 += -a + 1;
    }
  }

  cout << min(cnts, cnts2) << '\n';

  return 0;
}