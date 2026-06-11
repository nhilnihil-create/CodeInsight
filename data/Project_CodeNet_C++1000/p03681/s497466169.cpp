#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  const int MOD = 1000000007;
  int N, M;
  cin >> N >> M;

  int a = std::max(N, M);
  int b = std::min(N, M);

  long long sum = 1;
  if (a - b > 1) cout << 0 << endl;
  else {
    for (int i = 1; i <= a; i++) {
      sum *= i;
      sum %= MOD;
    }

    for (int i = 1; i <= b; i++) {
      sum *= i;
      sum %= MOD;
    }

    if (a == b) {
      sum *= 2;
      sum %= MOD;
    }

    cout << sum << endl;
  }

  return 0;
}
