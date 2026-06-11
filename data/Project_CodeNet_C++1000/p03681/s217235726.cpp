#include <bits/stdc++.h>
using namespace std;

long long int MOD = 1000000007;

int main() {
  long long int N, M;
  cin >> N >> M;
  
  if (abs(N - M) >= 2) cout << 0 << endl;
  
  else if (abs(N - M) == 1) {
    long long int fN = 1, fM = 1;
    for (long long int i = 1; i <= N; i++) {
      fN *= i;
      fN %= MOD;
    }
    for (long long int i = 1; i <= M; i++) {
      fM *= i;
      fM %= MOD;
    }
    cout << fN * fM % MOD;
  }
  
  else {
    long long int fN = 1;
    for (long long int i = 1; i <= N; i++) {
      fN *= i;
      fN %= MOD;
    }
    cout << fN * fN * 2 % MOD << endl;
  }
}