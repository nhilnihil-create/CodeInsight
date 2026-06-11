// https://atcoder.jp/contests/abc069/tasks/arc080_b

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int H_MAX = 100;
const int W_MAX = 100;
const int N_MAX = H_MAX * W_MAX;

int H, W;
int N;
int a[N_MAX];

int c[H_MAX][W_MAX];

void solve() {
  int k = 0;
  REP(i, N) REP(j, a[i]) {
    int y = k / W;
    int x = k % W;
    if (y % 2) x = W - 1 - x;
    c[y][x] = i + 1;
    k++;
  }
  REP(y, H) REP(x, W) printf("%d%c", c[y][x], x + 1 == W ? '\n' : ' ');
}

void input() {
  scanf("%d%d", &H, &W);
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
}

int main() {
  input();
  solve();
  return 0;
}
