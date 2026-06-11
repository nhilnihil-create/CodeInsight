#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  int64_t mod = 1000000000 + 7;
  int64_t power = 1;
  for (int i = 1; i <= n; i++) {
    power *= i;
    power %= mod;
  }

  cout << power << endl;
  return 0;
}