#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int N;
  cin >> N;
  map<int, int> A{};
  int over = 0;
  REP(i, N) {
    int a;
    cin >> a;
    if (3200 <= a) {
      over++;
      continue;
    }
    a /= 400;
    A[a]++;
  }
  int ans = 0;
  REP(i, 8) {
    if (0 < A[i]) ans++;
  }
  if (ans == 0) {
    ans++, over = max(0, over - 1);
  }
  cout << ans << " " << ans + over << endl;
}
