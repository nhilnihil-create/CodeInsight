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
typedef vector<bool> vb;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve(long long N, std::vector<std::vector<long long>> A) {
  vector<vb> need(N, vb(N, true));
  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        if (A[i][k] + A[k][j] < A[i][j]) {
          print(-1);
          return;
        } else if (A[i][k] + A[k][j] == A[i][j] && i != k && k != j) {
          need[i][j] = false;
        }
      }
    }
  }

  ll ans = 0;
  rep(i, N) {
    rep(j, N) {
      if (need[i][j]) {
        ans += A[i][j];
      }
    }
  }
  print(ans / 2);
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<std::vector<long long>> A(N, std::vector<long long>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%lld", &A[i][j]);
    }
  }
  solve(N, std::move(A));
  return 0;
}
