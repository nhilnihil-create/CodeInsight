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

const string YES = "Yes";
const string NO = "No";

void solve(long long N, std::vector<long long> a) {
  ll maxA = -1;
  ll minA = 1e6;
  ll maxCnt = 0;
  ll minCnt = 0;
  rep(i, N) {
    if (maxA < a[i]) {
      maxA = a[i];
      maxCnt = 1;
    } else if (maxA == a[i]) {
      maxCnt++;
    }

    if (minA > a[i]) {
      minA = a[i];
      minCnt = 1;
    } else if (minA == a[i]) {
      minCnt++;
    }
  }

  if (maxA == minA) {
    bool ok = true;
    // 全員がalone
    rep(i, N) {
      if (a[i] != N - 1) {
        ok = false;
        break;
      }
    }

    if (ok) {
      print(YES);
      return;
    }

    // 全員がnot alone
    if (2 * maxA <= N) {
      print(YES);
      return;
    }
  } else if (maxA - minA == 1) {
    if (minCnt < maxA && 2 * (maxA - minCnt) <= maxCnt) {
      print(YES);
      return;
    }
  }

  print(NO);
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve(N, std::move(a));
  return 0;
}
