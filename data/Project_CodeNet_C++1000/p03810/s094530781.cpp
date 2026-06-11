#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, n)
#define _ << " _ " <<
#define TRACE(x) cerr << #x << " = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug
#define TRACE(x)

using namespace std;

typedef long long llint;

const int MAXN = 100010;
int n, a[MAXN];

int solve() {
  llint sum = 0;
  int odd = 0;
  int one = 0;
  
  REP(i, n) {
    sum += a[i];
    if (a[i] % 2)
      ++odd;
    if (a[i] == 1)
      one = 1;
  }
  sum %= 2;

  if (one) return sum == n % 2 ? 0 : 1;
  
  if (n == 1) {
    return (a[0] + 1) % 2;
  } else if (n == 2) {
    return a[0] % 2 == 1 && a[1] % 2 == 1 ? 0 : 1;
  } else {
    if (sum == n % 2) {
      TRACE(odd _ sum);
      if (odd > 1) return 0;
      int g = 0;
      REP(i, n) {
	if (a[i] % 2) --a[i];
	g = __gcd(g, a[i]);
      }
      TRACE(g);
      REP(i, n) a[i] /= g;
      return solve() ^ 1;
    } else {
      return 1;
    }
  }
  return 0;
}

int main(void) {
  scanf("%d",&n);
  REP(i, n) scanf("%d",&a[i]);
  printf(solve() ? "First\n" : "Second\n");
  return 0;
}
