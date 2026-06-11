#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  string sa, sb, sc;
  cin >> sa >> sb >> sc;
  char now = 'a';
  while (true) {
    if (now == 'a') {
      if (sa.size() == 0) {
        cout << 'A' << endl;
        return 0;
      }
      now = sa[0];
      sa.erase(sa.begin());
    } else if (now == 'b') {
      if (sb.size() == 0) {
        cout << 'B' << endl;
        return 0;
      }
      now = sb[0];
      sb.erase(sb.begin());
    } else {
      if (sc.size() == 0) {
        cout << 'C' << endl;
        return 0;
      }
      now = sc[0];
      sc.erase(sc.begin());
    }
  }
}
