#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
#define accum(x) accumulate((x).begin(), (x).end(), 0)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i];

  // 偶数番目と奇数番目どちらを正にするかで2通り考え小さい方を答えにする

  ll ans1 = 0, ans2 = 0, tot = 0;
  rep(i, 0, n) {
    tot += a[i];
    if (i % 2 == 0 && tot >= 0) {
      ans1 += tot + 1;
      tot = -1;
    } else if (i % 2 == 1 && tot <= 0) {
      ans1 += -tot + 1;
      tot = 1;
    }
  }

  tot = 0;
  rep(i, 0, n) {
    tot += a[i];
    if (i % 2 == 1 && tot >= 0) {
      ans2 += tot + 1;
      tot = -1;
    } else if (i % 2 == 0 && tot <= 0) {
      ans2 += -tot + 1;
      tot = 1;
    }
  }

  cout << min(ans1, ans2) << endl;

  return 0;
}
