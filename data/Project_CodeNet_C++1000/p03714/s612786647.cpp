#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, s, n) for (int i = (s); i < (n); ++i)
#define repsr(i, n, s) for (int i = (n); i >= (s); --i)
#define repe(i, n) for (int i = 0; i <= (n); ++i)
const int64_t inf = (int64_t)1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  vector<int> as(3 * N);
  rep(i, 3 * N) cin >> as[i];
  
  priority_queue<int, vector<int>, greater<int>> pql;
  priority_queue<int> pqr;
  int64_t sum_l = 0;
  int64_t sum_r = 0;
  vector<int64_t> bs(N + 1, 0);


  rep(i, N) {
    sum_l += as[i];
    pql.push(as[i]);
  }
  bs[0] = sum_l;

  reps(i, N, 2 * N) {
    if (pql.top() < as[i]) {
      sum_l -= pql.top(); pql.pop();
      sum_l += as[i];
      pql.push(as[i]);
    }
    bs[i - N + 1] = sum_l;
  }


  reps(i, 2 * N, 3 * N) {
    sum_r += as[i];
    pqr.push(as[i]);
  }
  bs[N] -= sum_r;

  repsr(i, 2 * N - 1, N) {
    if (pqr.top() > as[i]) {
      sum_r -= pqr.top(); pqr.pop();
      sum_r += as[i];
      pqr.push(as[i]);
    }
    bs[i - N] -= sum_r;
  }

  int64_t ans = -inf;
  repe(i, N) ans = max(ans, bs[i]);
  cout << ans << "\n";

  return 0;
}
