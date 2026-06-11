// https://atcoder.jp/contests/abc074/tasks/arc083_a

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int B_MAX = 30;
const int D_MAX = 30;
const int E_MAX = 100;
const int F_MAX = 3'000;

int A, B, C, D, E, F;

void solve() {
  double vx = -1;
  int abcdx = 0;
  int cdx = 0;
  for (int a = 0; a * 100 <= F; a += A) {
    for (int ab = a; ab * 100 <= F; ab += B) {
      for (int c = 0; c <= ab * E && ab * 100 + c <= F; c += C) {
        int d = min(F - (ab * 100 + c), ab * E - c) / D * D;
        int cd = c + d;
        int abcd = ab * 100 + cd;
        if (abcd == 0) continue;
        double v = (double)cd / abcd;
        if (v > vx) {
          vx = v;
          abcdx = abcd;
          cdx = cd;
        }
      }
    }
  }
  printf("%d %d\n", abcdx, cdx);
}

void input() {
  scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F);
}

int main() {
  input();
  solve();
  return 0;
}
