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
  int N, M;
  cin >> N >> M;
  vector<int> A(N, 1), Red(N, 0);
  Red[0] = 1;
  REP(i, M) {
    int x, y;
    cin >> x >> y, x--, y--;
    if (Red[x] == 1) {
      Red[y] = 1;
    }
    A[x]--;
    A[y]++;
    if (A[x] == 0) {
      Red[x] = 0;
    }
  }
  ll ans = 0;
  REP(i, N) {
    if (Red[i] == 1) {
      ans++;
    }
  }
  cout << ans << endl;
}
