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
  vector<int> T(N), A(N);
  REP(i, N) cin >> T[i];
  REP(i, N) cin >> A[i];
  vector<int> tmin(N), tmax(N);
  REP(i, N) {
    if (i == 0 || (0 < i && T[i - 1] < T[i])) {
      tmin[i] = T[i];
      tmax[i] = T[i];
    } else {
      tmin[i] = 1;
      tmax[i] = T[i];
    }
  }
  vector<int> amin(N), amax(N);
  RREP(i, N) {
    if (i == N - 1 || (i < N - 1 && A[i + 1] < A[i])) {
      amin[i] = A[i];
      amax[i] = A[i];
    } else {
      amin[i] = 1;
      amax[i] = A[i];
    }
  }
  ll ans = 1;
  REP(i, N) {
    int mn = max(tmin[i], amin[i]);
    int mx = min(tmax[i], amax[i]);
    ans *= max(0ll, 1ll * (mx - mn + 1));
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}