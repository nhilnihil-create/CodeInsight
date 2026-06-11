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

void solve(long long N, long long M, std::vector<std::vector<long long>> A) {
  rep(i, N) {
    rep(j, M) { A[i][j]--; }
  }

  vector<bool> checked(M);
  ll ans = INF;
  rep(i, M) {
    vector<int> sum(M);
    rep(j, N) {
      rep(k, M) {
        if (!checked[A[j][k]]) {
          sum[A[j][k]]++;
          break;
        }
      }
    }

    ll maxSum = 0;
    ll maxSumi = 0;
    rep(k, M) {
      if (sum[k] > maxSum) {
        maxSum = sum[k];
        maxSumi = k;
      }
    }

    if (ans > maxSum) {
      ans = maxSum;
    }

    checked[maxSumi] = true;
  }

  print(ans);
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<std::vector<long long>> A(N, std::vector<long long>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%lld", &A[i][j]);
    }
  }
  solve(N, M, std::move(A));
  return 0;
}
