#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int MOD = round(1e9 + 7);
const int N = 2e5 + 5;

struct Point {
  int x, y;
  Point(int x, int y) :
    x(x), y(y) {
  }
};

int fact[N];

int power(int b, int p) {
  if (p == 0) return 1;
  int res = power(b, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * b % MOD;
  }
  return res;
}

int modInv(int x) {
  return power(x, MOD - 2);
}

void buildFact() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
  }
}

int getNoWays(const Point& p1, const Point& p2) {
  int dx = p2.x - p1.x;
  int dy = p2.y - p1.y;

  int res = 1LL * fact[dx + dy] * modInv(fact[dx]) % MOD;
  res = 1LL * res * modInv(fact[dy]) % MOD;

  return res;
}

int h, w, a, b;

int solve() {
  a = h - a + 1;
  int res = getNoWays(Point(1, 1), Point(h, w));

  int invalid = 0;
  for (int i = 1; i <= b; ++i) {
    int tmp = getNoWays(Point(1, 1), Point(a - 1, i));
    tmp = 1LL * tmp * getNoWays(Point(a, i), Point(h, w)) % MOD;
    invalid = (invalid + tmp) % MOD;
  }
  res = (res + MOD - invalid) % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  buildFact();

  cin >> h >> w >> a >> b;

  cout << solve();

}

