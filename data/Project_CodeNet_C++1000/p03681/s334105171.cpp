#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll const MOD = 1000000007LL;

ll factorization(ll k) {
  ll sum = 1;
  for (ll i = 1; i <= k; ++i) sum = (sum % MOD) * (i % MOD);
  return sum;
}

int main() {
  ll N, M;
  cin >> N >> M;
  if (abs(N - M) > 1) {
    cout << 0 << endl;
    return 0;
  }
  ll n_fact = factorization(N);
  ll m_fact = factorization(M);
  if (N == M) {
    cout << ((n_fact % MOD) * (m_fact % MOD) * 2) % MOD << endl;
    return 0;
  }
  cout << ((n_fact % MOD) * (m_fact % MOD)) % MOD << endl;
  return 0;
}