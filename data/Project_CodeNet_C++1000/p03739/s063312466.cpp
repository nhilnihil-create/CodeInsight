#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greater<int>()

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

const int INF = 1001001001;
const int MOD = 1000000007;
const long long INFL = (1LL << 60);
const double EPS = 1e-9;

bool meet(vi a) {
  bool ret = true;
  bool pos = (a[0] > 0);
  int sum = a[0];
  FOR(i, 1, a.size()) {
    sum += a[i];
    if ((pos && i % 2 && sum >= 0) || (pos && !(i % 2) && sum <= 0) ||
        (!pos && i % 2 && sum <= 0) || (!pos && !(i % 2) && sum >= 0)) {
      ret = false;
      break;
    }
  }
  return ret;
}

uint64_t solve(vi a, uint64_t res) {
  int sum = a[0];
  bool pos = (a[0] > 0);
  FOR(i, 1, a.size()) {
    if ((pos && i % 2 && sum + a[i] >= 0) ||
        (!pos && !(i % 2) && sum + a[i] >= 0)) {
      res += abs(sum + a[i] - (-1));
      a[i] = -1 - sum;
    } else if ((pos && !(i % 2) && sum + a[i] <= 0) ||
               (!pos && i % 2 && sum + a[i] <= 0)) {
      res += abs(sum + a[i] - 1);
      a[i] = 1 - sum;
    }
    sum += a[i];
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  vi a(N);
  rep(i, N) cin >> a[i];
  bool flg = meet(a);

  bool pos = (a[0] > 0);
  bool isZero = (a[0] == 0);
  uint64_t res = 0;
  if (isZero) {
    res++;
    a[0] = 1;
  }
  uint64_t res1 = solve(a, res);

  res = 0;
  if (pos) {
    res += abs(a[0] - (-1));
    a[0] = -1;
  } else if (isZero) {
    res++;
    a[0] = -1;
  } else {
    res += abs(a[0] - 1);
    a[0] = 1;
  }
  uint64_t res2 = solve(a, res);

  res = min(res1, res2);
  if (flg) res = 0;

  cout << res << endl;
}