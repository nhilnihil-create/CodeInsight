#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, Y) for (int(X) = 0; (X) < (Y); ++(X))
#define rrep(X, Y) for (int(X) = (Y)-1; (X) >= 0; --(X))
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const long long MOD = 1000000007;

class Combination {
private:
  vector<long long> fac_;
  vector<long long> finv_;
  vector<long long> inv_;
  long long prime_;

public:
  Combination(long long n, long long prime) {
    fac_ = vector<long long>(n + 1);
    finv_ = vector<long long>(n + 1);
    inv_ = vector<long long>(n + 1);
    prime_ = prime;

    fac_[0] = fac_[1] = 1;
    finv_[0] = finv_[1] = 1;
    inv_[1] = 1;
    for (long long i = 2; i <= n; i++) {
      fac_[i] = fac_[i - 1] * i % prime_;
      inv_[i] = prime_ - inv_[prime_ % i] * (prime_ / i) % prime_;
      finv_[i] = finv_[i - 1] * inv_[i] % prime_;
    }
  }

  // nCk
  long long getCombination(long long n, long long k) {
    if (n < k)
      return 0;
    if (n < 0 || k < 0)
      return 0;

    return fac_[n] * (finv_[k] * finv_[n - k] % prime_) % prime_;
  }
};

void solve(long long H, long long W, long long A, long long B) {
  Combination comb = Combination(1e6, MOD);

  ll ans = 0;
  for (ll b = B + 1; b <= W; b++) {
    ll n1 = (H - A - 1) + (b - 1);
    ll n2 = (A - 1) + (W - b);
    ans +=
        comb.getCombination(n1, (H - A - 1)) * comb.getCombination(n2, (A - 1));
    ans %= MOD;
  }

  print(ans);
}

int main() {
  long long H;
  scanf("%lld", &H);
  long long W;
  scanf("%lld", &W);
  long long A;
  scanf("%lld", &A);
  long long B;
  scanf("%lld", &B);
  solve(H, W, A, B);
  return 0;
}
