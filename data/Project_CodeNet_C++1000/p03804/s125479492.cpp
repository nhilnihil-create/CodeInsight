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
  vector<string> A(N), B(M);
  REP(i, N) cin >> A[i];
  REP(i, M) cin >> B[i];
  bool ok = false;
  REP(i, N - M + 1) {
    REP(j, N - M + 1) {
      bool t = true;
      REP(k, M) REP(l, M) {
        if (A[i + k][j + l] != B[k][l]) t = false;
      }
      if (t) {
        ok = true;
      }
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}