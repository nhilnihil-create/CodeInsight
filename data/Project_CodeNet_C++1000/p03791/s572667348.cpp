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
//#define debug
//#define TRACE(x)

using namespace std;

typedef long long llint;

const int MAXN = 100010;
const int MOD = 1e9 + 7;

int n, x[MAXN];

int main(void) {
  scanf("%d",&n);
  REP(i, n) scanf("%d",&x[i]);

  llint sol = 1;
  
  int t = 0;
  REP(i, n) {
    int b = t;
    sol = sol * (b + 1) % MOD;
    ++t;
    while (t > (x[i] + 1) / 2)
      --t;
  }

  cout << sol << endl;
  
  return 0;
}
