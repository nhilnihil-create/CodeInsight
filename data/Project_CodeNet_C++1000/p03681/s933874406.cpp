#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N, M;
  cin >> N >> M;

  if(abs(N - M) >= 2) {
    cout << 0 << endl;
  }
  else {
    long long pow_N = N % MOD, pow_M = M % MOD;
    for(int i = 1; i < N; i++) {
      pow_N *= i;
      pow_N %= MOD;
    }
    for(int i = 1; i < M; i++) {
      pow_M *= i;
      pow_M %= MOD;
    }
    if (abs(N - M) == 1) {
      cout << (pow_N * pow_M) % MOD << endl;
    }
    else {
      cout << 2 * (pow_N * pow_M) % MOD << endl;
    }
  }

  return 0;
}
