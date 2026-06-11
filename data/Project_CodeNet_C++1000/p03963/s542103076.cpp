#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

const ll MOD = 1e9 + 7;

ll pow_fast(ll n, ll k) {
  if (k == 0) {
    return 1LL;
  }
  if (k == 1) {
    return n;
  }

  if (k % 2 == 0) {
    ll tmp = pow_fast(n, k / 2);
    return tmp * tmp % MOD;
  } else {
    ll tmp = pow_fast(n, (k - 1) / 2);
    tmp *= tmp;
    tmp %= MOD;
    return tmp * n % MOD;
  }
}

int main() {
  ll N, K;
  cin >> N >> K;
  cout << (K * pow_fast(K - 1, N - 1)) << endl;
}