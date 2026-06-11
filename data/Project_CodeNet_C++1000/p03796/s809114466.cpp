#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;

int main() {
  int64_t n;
  cin >> n;
  int64_t power = 1;
  for (int64_t i = 1; i <= n; ++i) {
    power = power * i % MOD;
  }
  cout << power << endl;
}
