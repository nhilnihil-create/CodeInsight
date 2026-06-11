#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
  long long N, M;
  cin >> N >> M;

  long long dog = 1;
  for (int i = 1; i <= N; i++) {
    dog *= i;
    dog %= MOD;
  }

  long long monkey = 1;
  for (int i = 1; i <= M; i++) {
    monkey *= i;
    monkey %= MOD;
  }

  if (abs(N - M) >= 2)
    cout << 0 << endl;
  else if (abs(N - M) == 1)
    cout << (dog * monkey) % MOD << endl;
  else
    cout << (dog * monkey * 2) % MOD << endl;
}