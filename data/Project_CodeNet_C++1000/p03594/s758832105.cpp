#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 505;

char col[] = "RGBY";

int main(void) {
  int H, W, D;
  scanf("%d %d %d", &H, &W, &D);
  REP(i, H) {
    REP(j, W) {
      int a = (i + j) % (2 * D);
      int b = (i - j) % (2 * D);
      if (b < 0) b += 2 * D;

      int r = (a < D) * 2 + (b < D);
      putchar(col[r]);
    }
    putchar('\n');
  }
  
  return 0;
}
