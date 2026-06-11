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
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  REP(i, N) cin >> a[i];
  vector<ll> sum1(N + 1), sum2(N + 1);
  sum1[0] = 0, sum2[0] = 0;
  REP(i, N) {
    sum1[i + 1] = sum1[i] + a[i];
    sum2[i + 1] = sum2[i] + max(0ll, 1ll * a[i]);
  }
  ll ans = 0;
  REP(i, N - K + 1) {
    ll tmp = sum2[i] - sum2[0] + max(0ll, sum1[i + K] - sum1[i]) + sum2[N] -
             sum2[i + K];
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}