#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int64_t comb(int64_t n, int64_t r) {
  int64_t ret = 1;
  for (int64_t i = 1; i <= r; i++) {
    ret = ret * (n - i + 1) / i;
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  int N, A, B;
  cin >> N >> A >> B;
  vector<int64_t> V(N);
  unordered_map<int, int> cnt;
  rep(i, N) {
    cin >> V[i];
    cnt[V[i]]++;
  }
  sort(V.begin(), V.end(), greater<int64_t>());
  int64_t SUM = 0;
  rep(i, A) { SUM += V[i]; }
  double AVG = (double)SUM / (double)A;
  cout << setprecision(20) << AVG << endl;

  int anum = cnt[V[A - 1]];
  int commit = 0;
  rep(i, A) {
    if (V[i] == V[A - 1]) break;
    ++commit;
  }

  int64_t count = 0;
  if (commit == 0) {
    for (int i = A; i <= B; ++i) {
      count += comb(anum, i);
    }
  } else {
    count += comb(anum, A - commit);
  }
  cout << count << endl;
  return 0;
}
