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

#define rep(X, S, E) for (int(X) = (S); (X) < (E); ++(X))
#define rrep(X, S, E) for (int(X) = (E)-1; (X) >= (S); --(X))
#define itrep(X, Y) for (auto(X) = (Y).begin(); (X) != (Y).end(); (X)++)
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
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll INF = 9 * 1e18;
const ll MOD = 1e9 + 7;

bool isOk(ll K, long long N, long long A, long long B,
          std::vector<long long> &h) {
  vl hcopy(N);
  rep(n, 0, N) { hcopy[n] = h[n] - K * B; }

  ll cnt = 0;
  rep(n, 0, N) {
    if (hcopy[n] > 0) {
      cnt += ceil((double)hcopy[n] / (A - B));
    }
  }

  return cnt <= K;
}

void solve(long long N, long long A, long long B, std::vector<long long> h) {
  ll kl = 0;
  ll kr = 1e9;
  ll km = (kl + kr) / 2;
  ll ok = -1;
  while (kl <= kr) {
    if (isOk(km, N, A, B, h)) {
      ok = km;
      kr = km - 1;
    } else {
      kl = km + 1;
    }
    km = (kl + kr) / 2;
  }
  print(ok);
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long A;
  scanf("%lld", &A);
  long long B;
  scanf("%lld", &B);
  std::vector<long long> h(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &h[i]);
  }
  solve(N, A, B, std::move(h));
  return 0;
}
