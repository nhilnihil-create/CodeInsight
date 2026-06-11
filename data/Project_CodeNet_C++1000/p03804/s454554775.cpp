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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  vector<string> b(m);
  REP(i, n) { cin >> a.at(i); }
  REP(i, m) { cin >> b.at(i); }

  REP(i, n - m + 1) {
    REP(j, n - m + 1) {
      bool f = true;
      REP(k, m) {
        //cout << a.at(i + k).substr(j, m) <<"  "<<b.at(k)<< "\n";
        if (b.at(k) != a.at(i + k).substr(j, m)) f = false;
      }
     // cout  << "\n";
      if (f) {
        cout << "Yes\n";
        return 0;
      }
    }
  }

  cout << "No\n";
  return 0;
}
