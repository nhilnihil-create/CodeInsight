#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MOD = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  int d = abs(a - b);
  vector<long long> ex(100001);
  ex[0] = 1;
  for (long long i = 1; i <= 100000; i++) {
    ex[i] = (ex[i-1] * i) % MOD;
  }
  if (d == 0) {
    cout << ex[a] * ex[a] * 2 % MOD << endl;
  } else if (d == 1) {
    cout << ex[a] * ex[b] % MOD << endl;
  } else {
    cout << 0 << endl;
  }
}
