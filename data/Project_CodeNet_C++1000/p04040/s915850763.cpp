#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;
const int N = 1111111;

inline void add(int& a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline void sub(int& a, int b) {
  a -= b;
  if (a < 0) {
    a += md;
  }
}

inline int mul(int a, int b) {
  return a * 1LL * b % md;
}

inline int power(int a, long long b) {
  int ret = 1;
  while (b > 0) {
    if (b & 1) {
      ret = mul(ret, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}

inline int inv(int a) {
  return power(a, md - 2);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> fact(N);
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  int ans = 0;
  for (int i = b + 1; i <= w; ++i) {
    int cnt = 1;
    cnt = mul(cnt, mul(fact[h - a - 1 + i - 1], mul(inv(fact[h - a - 1]), inv(fact[i - 1]))));
    cnt = mul(cnt, mul(fact[a - 1 + w - i], mul(inv(fact[a - 1]), inv(fact[w - i]))));
    add(ans, cnt);
  }
  cout << ans << '\n';
  return 0;
}
