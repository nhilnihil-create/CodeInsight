#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <bitset>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < (n); i++)

using namespace std;

void solve() {
  long N, x;
  cin >> N >> x;

  vector<long> a(N);
  rep (i, N) cin >> a[i];

  vector<long> state = a;

  long ans = 0;
  rep (i, N) ans += state[i];

  for (long i = 1; i < N; i++) {
    rep(j, N) state[j] = min(state[j], a[(j-i+N)%N]);
    long tmp = 0;
    rep (j, N) tmp += state[j];
    tmp += i * x;
    ans = min(ans, tmp);
  }

  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
