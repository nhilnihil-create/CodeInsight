#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int N;
  cin >> N;
  int A[N][N];
  bool cand[N][N];
  REP(i, N) REP(j, N) {
    cin >> A[i][j];
    cand[i][j] = true;
  }
  REP(k, N) REP(i, N) REP(j, N) {
    if (A[i][j] > A[i][k] + A[k][j]) {
      cout << -1 << endl;
      return 0;
    }
    if (A[i][j] == A[i][k] + A[k][j] && 0 < A[i][k] && 0 < A[k][j]) {
      cand[i][j] = false;
    }
  }
  ll ans = 0;
  REP(i, N) REP(j, N) {
    if (cand[i][j]) ans += A[i][j];
  }
  cout << ans / 2 << endl;
  return 0;
}