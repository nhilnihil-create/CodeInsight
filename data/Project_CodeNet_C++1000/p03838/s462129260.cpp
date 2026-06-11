#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define INF (INT_MAX / 4)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#define TIMER_S(start) chrono::system_clock::time_point start = chrono::system_clock::now();
#define TIMER_E(end) chrono::system_clock::time_point end = chrono::system_clock::now();
#define TIME(start, end) cout << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()) << "ms" << "\n";
/* clang-format on */

int main() {
  ll ans = 0, x, y;
  cin >> x >> y;
  if ((0 <= x && x < y) || (x < y && y < 0)) ans = abs(y - x);
  if ((0 < y && y < x) || (y < x && x < 0)) ans = x - y + 2;
  if ((x < 0 && 0 < y) || (y < 0 && 0 < x))
    ans = min(abs(x - y), abs(x + y) + 1);
  if (abs(x) == abs(y)) ans = 1;
  if (x == y) ans = 0;
  if (x == 0 && y < x) ans = -y + 1;
  if (y == 0 && 0 < x) ans = x + 1;
  if (y == 0 && x < 0) ans = -x;
  cout << ans << endl;
  return 0;
}
