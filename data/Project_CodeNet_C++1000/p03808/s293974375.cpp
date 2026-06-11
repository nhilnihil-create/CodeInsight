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
const ll MOD = 1e9 + 7;

const string YES = "YES";
const string NO = "NO";

void solve(long long N, std::vector<long long> A) {
  if (N == 1) {
    print(YES);
    return;
  }

  ll sum = 0;
  rep(i, 0, N) { sum += A[i]; }

  vl diff(N);
  rep(i, 0, N - 1) { diff[i] = A[i + 1] - A[i]; }
  diff[N - 1] = A[0] - A[N - 1];

  ll maxN = 0;
  rep(i, 0, N) { maxN = max(maxN, diff[i]); }
  rep(i, 0, N) { diff[i] -= maxN; }

  ll cnt = 0;
  rep(i, 0, N) {
    if (abs(diff[i]) % N != 0) {
      print(NO);
      return;
    } else {
      cnt += abs(diff[i]) / N;
    }
  }

  if (maxN == cnt && sum - cnt * (N + 1) * N / 2 == 0) {
    print(YES);
  } else {
    print(NO);
  }
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}
