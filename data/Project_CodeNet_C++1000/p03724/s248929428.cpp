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

const string YES = "YES";
const string NO = "NO";

void solve(long long N, long long M, std::vector<long long> a,
           std::vector<long long> b) {
  vl sum(N);
  rep(i, M) {
    sum[--a[i]]++;
    sum[--b[i]]++;
  }

  itrep(s, sum) {
    if (*s % 2 != 0) {
      print(NO);
      return;
    }
  }
  print(YES);
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> a(M);
  std::vector<long long> b(M);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &a[i]);
    scanf("%lld", &b[i]);
  }
  solve(N, M, std::move(a), std::move(b));
  return 0;
}
