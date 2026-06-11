#include <bits/stdc++.h>

using namespace std;

typedef long long li;

const int N = 100100;
const int MOD = 1e9 + 7;

li z[20][N];

void init() {
  for (int i = 0; i < N; ++i) {
    z[0][i] = i;
  }
  for (int i = 1; i < 20; ++i) {
    int L = 1 << i;
    if (L >= N)
      break;
    int h = L / 2;
    for (int j = 0; j + L <= N; ++j) {
      z[i][j] = (z[i - 1][j] * z[i - 1][j + h]) % MOD;
    }
  }
}

int Ank2(int n, int k) {
  int fm = n - k + 1, to = n;
  int span = to + 1 - fm;
  int off = fm;
  li res = 1;
  for (int b = 20; b >= 0; --b) {
    int L = (1 << b);
    if (span & L) {
      res = (res * z[b][off]) % MOD;
      off += L;
    }
  }
  return int(res);
}

int main() {
  init();
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    b[i] = (a[i] +  1) / 2;
  }
  int p = 0;
  li cur = 1;
  for (int id = 0; id < n; ++id) {
    p += 1;
    int diff = p - b[id];
    if (diff > 0) {
      cur = (cur * Ank2(p, diff)) % MOD;
      p -= diff;
    }
  }
  cur = (cur * Ank2(p, p)) % MOD;
  printf("%lld\n", cur);
  return 0;
}
