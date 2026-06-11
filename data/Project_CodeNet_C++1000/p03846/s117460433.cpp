#include <bits/stdc++.h>
using namespace std;

long long int MOD = 1000000007;

long long int modpow(long long int a, long long int n, long long int mod) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    B.at(A) += 1;
  }
  if (N % 2 == 1) {
    bool X = true;
    if (B.at(0) != 1) X = false;
    for (int i = 2; i < N; i += 2) {
      if (B.at(i) != 2) {
        X = false;
        break;
      }
    }
    if (X) cout << modpow((long long int)2, (long long int)(N - 1) / 2, MOD) << endl;
    else cout << 0 << endl;
  }
  else {
    bool X = true;
    for (int i = 1; i < N; i += 2) {
      if (B.at(i) != 2) {
        X = false;
        break;
      }
    }
    if (X) cout << modpow((long long int)2, (long long int)N / 2, MOD) << endl;
    else cout << 0 << endl;
  }
}