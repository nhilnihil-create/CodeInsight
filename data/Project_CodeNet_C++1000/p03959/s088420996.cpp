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
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const long long MOD = 1000000007;

void solve(long long N, std::vector<long long> T, std::vector<long long> A) {
  vector<bool> fixed(N);
  vl num(N);

  ll maxHeight = 0;
  rep(n, N) {
    if (maxHeight < T[n]) {
      maxHeight = T[n];
      fixed[n] = true;
      num[n] = T[n];
    } else {
      num[n] = num[n - 1];
    }
  }

  maxHeight = 0;
  rrep(n, N) {
    // 矛盾チェック
    if (fixed[n] && num[n] > A[n]) {
      print(0);
      return;
    }

    if (maxHeight < A[n]) {
      maxHeight = A[n];

      // 矛盾チェック
      if (fixed[n] && num[n] != A[n]) {
        print(0);
        return;
      }

      fixed[n] = true;
      num[n] = A[n];
    } else {
      if (!fixed[n]) {
        num[n] = min(num[n], num[n + 1]);
      }
    }
  }

  ll ans = 1;
  rep(n, N) {
    if (!fixed[n]) {
      ans *= num[n];
      ans %= MOD;
    }
  }
  print(ans);
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> T(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &T[i]);
  }
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(T), std::move(A));
  return 0;
}
