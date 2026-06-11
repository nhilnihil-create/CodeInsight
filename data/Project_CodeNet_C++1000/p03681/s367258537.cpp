#include <iostream>

using namespace std;

const int MOD = 1000000007;

long long pow(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = res * x % MOD;
    x = x * x % MOD;
    n = n / 2;
  }
  return res;
}

long long modInverse(long long x) {
  return pow(x, MOD - 2);
}

long long fact[100005];

int main() {
  fact[0] = 1;
  for (int i = 1; i <= 100000; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }

  int N, M;
  cin >> N >> M;

  if (abs(N - M) > 1) {
    cout << 0 << endl;
    return 0;
  }
  if ((N + M) & 1) {
    cout << fact[N] * fact[M] % MOD << endl;
  } else {
    cout << fact[N] * fact[M] % MOD * 2 % MOD << endl;
  }
}
