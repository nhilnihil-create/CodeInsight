#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for(int i = 1, i##_len = (n); i < i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define PRINT(A) std::cout << (#A) << ":" << (A) << std::endl;
using namespace std;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9;

const int MAX = 210000;
long long fac[MAX], finv[MAX], inv[MAX];

void combination_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long combination(int n, int k) {
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  combination_init();
  int y = H - A - 1;
  int x = B;
  ll ans = 0;
  while(x <= W - 1 && y >= 0) {
    ans = (ans + combination(x + y, y) * combination(H + W - x - y - 2, H - y - 1) % MOD) % MOD;
    x++;
    y--;
  }
  cout << ans << endl;
}
