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
const ll INF = 1e16;

void solve(long long N, long long K, std::vector<long long> A,
           std::vector<long long> B) {
  ll ans = 0;
  rep(j, 0, N) {
    if ((K | A[j]) == K) {
      ans += B[j];
    }
  }

  rep(i, 0, 30) {
    if (!(K >> i & 1)) {
      continue;
    }

    ll mask = (1LL << i) - 1;
    ll kb = (K & ~(1LL << i)) | mask;

    ll tmp = 0;
    rep(j, 0, N) {
      if ((kb | A[j]) == kb) {
        tmp += B[j];
      }
    }

    ans = max(ans, tmp);
  }
  print(ans);
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  std::vector<long long> A(N);
  std::vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
    scanf("%lld", &B[i]);
  }
  solve(N, K, std::move(A), std::move(B));
  return 0;
}
