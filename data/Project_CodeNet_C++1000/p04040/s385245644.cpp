#include <iostream>

using namespace std;

typedef long long llong;

const int MOD = 1000000007;

struct modint {
  llong val;

  modint () {
    val = 0;
  }

  modint (llong _val) {
    val = _val % MOD;
  }
};

modint operator+ (modint p, modint q) {
  return modint((p.val + q.val) % MOD);
}

modint operator- (modint p, modint q) {
  return modint((p.val - q.val + MOD) % MOD);
}

modint operator- (modint p) {
  return modint(0) - p;
}

modint operator* (modint p, modint q) {
  return modint((p.val * q.val) % MOD);
}

modint operator^ (modint p, int q) {
  modint pows [30];

  pows[0] = p;
  for (int i = 1; i < 30; i++) {
    pows[i] = pows[i - 1] * pows[i - 1];
  }

  modint ans (1);
  for (int i = 0; i < 30; i++) {
    if (q & 1 << i) {
      ans = ans * pows[i];
    }
  }

  return ans;
}

modint operator/ (modint p, modint q) {
  return p * (q ^ (MOD - 2));
}

const int MAX_N = 200005;

modint fact [MAX_N];

modint choose (int n, int k) {
  return fact[n] / (fact[k] * fact[n - k]);
}

int main () {
  fact[0] = modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * modint(i);
  }

  int height, width, a, b;
  cin >> height >> width >> a >> b;

  /* we have made b right-moves now */
  modint ans (0);
  for (int i = 0; i < height - a; i++) {
    ans = ans + choose(b - 1 + i, i) * choose(height - 1 + width - 1 - (b + i), width - 1 - b);
  }

  cout << ans.val << endl;
}
