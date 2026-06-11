#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (INT_MAX / 4)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
/* clang-format off */
#define TIMER_S(start) chrono::system_clock::time_point start = chrono::system_clock::now();
#define TIMER_E(end) chrono::system_clock::time_point end = chrono::system_clock::now();
#define TIME(start, end) cout << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()) << "ms" << "\n";
/* clang-format on */

vector<ll> lc(90, -1);

int main() {
  int n;
  ll n1 = 0, n2 = 0;
  cin >> n;
  vector<int> a(n);
  REP(i, n) { cin >> a.at(i); }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int pre = -1;
  int cnt = 1;
  REP(i, n) {
    if (a.at(i) == pre) {
      cnt++;
      if (n1 == 0)
        n1 = pre;
      else if (n2 == 0) {
        if (n1 == a.at(i)) {
          if (cnt >= 4) n2 = pre;
        }else
          n2 = pre;
      }
    } else {
      cnt = 1;
    }
    pre = a.at(i);
  }
  cout << n1 * n2 << "\n";
  return 0;
}